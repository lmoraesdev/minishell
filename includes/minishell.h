/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:28:02 by lbatista          #+#    #+#             */
/*   Updated: 2023/03/07 02:26:14 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <dirent.h>
# include <errno.h>
# include <signal.h>

# define SUCCESS 0
# define FAILURE 1

# define SPC 32
# define PIPE 124
# define INPUT 60
# define HEREDOC 6060
# define TRUNC 62
# define APPEND 6262
# define WORD 42
# define S_QUOTE 39
# define D_QUOTE 34

# define EXIT 2
# define EXPORT 3
# define UNSET 4
# define CD 5

# define TOO_MANY_ARG "too many arguments"
# define UNCLOSED_QUOTES "unclosed quotes"
# define SYNTAX_ERR_PIPE "syntax error near unexpected token `|'"
# define SYNTAX_ERR_INPUT "syntax error near unexpected token `<'"
# define SYNTAX_ERR_HEREDOC "syntax error near unexpected token `<<'"
# define SYNTAX_ERR_TRUNC "syntax error near unexpected token `>'"
# define SYNTAX_ERR_APPEND "syntax error near unexpected token `>>'"
# define SYNTAX_ERR_NEWLINE "syntax error near unexpected token `newline'"
# define IS_DIR "Is a directory"
# define NO_FILE_DIR "No such file or directory"
# define NO_DIR "Not a directory"
# define INVALID_PERMISSION "Permission denied"
# define CMD_NOT_FOUND "command not found"
# define QUIT_HEREDOC "here-document delimited by end-of-file"
# define NOT_VALID_ID "not a valid identifier"
# define NUM_REQ "numeric argument required"

# define MAG "\001\033[1;35m\002"
# define CYN "\001\033[1;36m\002"
# define RESET "\001\033[0m\002"

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_token
{
	int				value;
	struct s_token	*next;
}	t_token;

typedef struct s_quotes
{
	int		type;
	bool	in;
}	t_quotes;

typedef struct s_expand
{
	char	**split;
	char	*result;
	bool	space;
	char	*find_dollar;
}	t_expand;

typedef struct s_split
{
	char	**words;
	int		num_word;
}	t_split;

typedef struct s_counter
{
	int	word;
	int	redirect;
}	t_counter;

typedef struct s_cmd_value
{
	char	**word;
	char	**redirect;
}	t_cmd_value;

typedef struct s_cmdtable
{
	char				**word;
	int					fdin;
	int					fdout;
	char				**redirect;
	char				*err_file;
	int					err_nb;
	struct s_cmdtable	*next;
}	t_cmdtable;

typedef struct s_data
{
	t_token		*head_token;
	t_env		*head_env;
	t_cmdtable	*head_cmd;
	char		*cmd_line;
	char		*env_value;
	char		*cmd_path;
	char		**splited_cmdl;
	char		*prompt_line;
	char		*path_value;
	int			status;
	bool		is_pipe;
	bool		interrupt_heredoc;
}	t_data;

extern t_data	g_data;

// BUILTINS
int		exec_builtin_parent(t_cmdtable *head_table, int builtin);
void	builtin_exit(t_cmdtable *head_table);
void	builtin_export(t_cmdtable *head_table);
void	put_export(int fd);
int		export_error(char *variable);
void	exec_builtin_child(t_cmdtable *head_table);
void	builtin_echo(char **word);
void	builtin_pwd(void);
void	builtin_unset(t_cmdtable *cmd_table);
void	builtin_env(t_cmdtable *head_table);
int		save_env_var(char *variable, int validate);
void	builtin_cd(t_cmdtable *cmd_table);
int		check_builtin(t_cmdtable *cmd_table);

// COMMAND_TABLE
void	create_cmd_table(void);
void	cmd_lst_add_front(t_cmdtable **head_cmd, t_cmd_value cmd_v);
void	free_cmd_lst(t_cmdtable **head_cmd);
bool	is_redirect(char *cmd);
void	init_count(t_counter *count);
void	init_cmd_value(t_cmd_value *cmd_value, t_counter *count);
bool	is_var_expansion(char *str);
void	exec_heredoc(t_cmdtable *head_cmd, char *eof);
void	open_redirection(void);

// EXEC
void	check_cmd(char **word);
void	fork_it(void);
void	exec_cmd(t_cmdtable *head_table);
char	*search_env_value(char *var);
void	open_pipe(void);
void	wait_all_pids(int pid[1024], int id);
void	close_node_fds(t_cmdtable *head);
void	close_list_fds(t_cmdtable *head);
void	dup_fds(t_cmdtable *head);
void	is_dir_exit(char *word);
void	no_such_file_exit(char *word, int status);
void	invalid_permission_exit(char *word, int status);

// EXPAND
void	parse_expansion(char **word);
int		is_double_single_quotes(char *str);
int		dont_expand(char *str);
void	clean_quotes(char **str, char quote);
void	expand(void);
char	*expand_env(char *word);
void	save_str(char **result, char *str, bool space);
void	save_prefix(char **result, char *str, int diff);
void	save_exit_code_suffix(char **result, char *str, char *exit, bool spc);
void	save_exit_code(char **result, char *str, bool space);
void	save_expand_env(char **result, char *str, bool space);
void	strcat_space(char **result, char *str, bool space);
void	add_space(char **result);

// PARSER
void	lexer(void);
int		get_token(char *cmd);
int		token_lst_add_back(t_token **head_token, int value);
void	free_token_lst(t_token **head_token);
void	tokenizer(void);
int		parser(void);
int		syntax_error(char *msg);
int		count_cmd_words(char *cmd);
int		is_reserved_word(char c);
bool	check_reserved_word(char **cmd, int *word_count, bool is_word);
int		find_first_reserved_char(char *cmd);
void	save_word_with_quotes(t_split *split, char **cmd, int *i);
void	save_reserved_word(t_split *split, char **cmd, int *i);
char	**split_cmd(char *cmd);

// QUOTES
int		is_quote_type(char ch);
bool	validate_quote_closed(void);
char	*str_without_quotes(char *str);
void	skip_quotes(char **cmd);

// SYSTEM
void	save_env(char **envp);
int		env_lst_add_back(t_env **head_env, char *name, char *value);
char	*get_env_value(char *envp, char *env_key);
void	get_prompt(void);
char	*colored_login(char **user, char **hostname);
char	*colored_prompt_line(char **login);
void	free_env_lst(t_env **head_env);
void	error_msg_exit(char *title, char *msg, int fd);
void	sig_handle_exec_parent(int signum);
void	sig_handle_heredoc_child(int signal);
void	sig_handle_minishell(int signum);
void	del_node(t_env **env_list, char *word);
void	del_first_node(t_env **head_env);

// UTILS
void	put_msg(char *title, char *msg, int fd);
void	put_msg_cmd(char *title, char *cmd, char *msg, int fd);
char	*remove_spaces_around_str(char *str);
void	free_minishell(void);
void	minishell_init(void);
int		init_expand(t_expand *exp, char *str);
int		strcmp_eq(char *s1, char *s2);
void	clear_minishell(void);

// VARIABLE
bool	validate_var_name(char *var_name);
bool	is_equal_sign(char *cmd);

#endif
