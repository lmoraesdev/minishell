/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:37:58 by lbatista          #+#    #+#             */
/*   Updated: 2023/03/02 20:03:34 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	GET_TOKEN
**	------------
**	DESCRIPTION
**	Check the cmd character is pipe, heredoc, input, append, trunc or word.
**	PARAMETERS
**	#1. The array (cmd);
**	RETURN VALUES
**	Return token
*/
int	get_token(char *cmd)
{
	int	cmd_len;

	cmd_len = ft_strlen(cmd);
	if (cmd_len > 2)
		return (WORD);
	if (cmd_len == 1 && ft_strncmp_eq(cmd, "|", 1))
		return (PIPE);
	if (cmd_len == 2 && ft_strncmp_eq(cmd, "<<", 2))
		return (HEREDOC);
	if (cmd_len == 1 && ft_strncmp_eq(cmd, "<", 1))
		return (INPUT);
	if (cmd_len == 2 && ft_strncmp_eq(cmd, ">>", 2))
		return (APPEND);
	if (cmd_len == 1 && ft_strncmp_eq(cmd, ">", 1))
		return (TRUNC);
	return (WORD);
}

/*	LEXER
**	------------
**	DESCRIPTION
**	Loops through the cmd matrix and does lexer.
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/
void	lexer(void)
{
	int	i;
	int	token;

	i = 0;
	while (g_data.splited_cmdl[i])
	{
		token = get_token(g_data.splited_cmdl[i]);
		token_lst_add_back(&g_data.head_token, token);
		i++;
	}
	return ;
}
