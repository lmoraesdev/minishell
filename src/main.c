/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:27:14 by lbatista          #+#    #+#             */
/*   Updated: 2023/03/07 02:24:15 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	g_data;

/*	RUN_CMD
**	------------
**	DESCRIPTION
**	Calls the parsing functions and executes the command.
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/
void	run_cmd(void)
{
	tokenizer();
	if (g_data.splited_cmdl == NULL)
		return ;
	lexer();
	if (parser() == FAILURE)
		return ;
	create_cmd_table();
	expand();
	open_pipe();
	open_redirection();
	if (!g_data.interrupt_heredoc)
		fork_it();
}

int	main(int argc, char *argv[], char *envp[])
{
	(void)argv;
	if (argc > 1)
		error_msg_exit("minishell", TOO_MANY_ARG, 2);
	minishell_init();
	save_env(envp);
	g_data.path_value = search_env_value("PATH");
	while (1)
	{
		signal(SIGINT, sig_handle_minishell);
		signal(SIGQUIT, SIG_IGN);
		get_prompt();
		if (*g_data.cmd_line)
		{
			if (validate_quote_closed())
				run_cmd();
			else
				put_msg("minishell", UNCLOSED_QUOTES, 2);
			free_minishell();
		}
	}
	return (0);
}
