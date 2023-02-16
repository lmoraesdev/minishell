/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_minishell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:33:31 by lbatista          #+#    #+#             */
/*   Updated: 2023/02/16 12:33:42 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	CLEAR_MINISHELL
**	------------
**	DESCRIPTION
**	Free allocation memory in data struct and initialize values.
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/
void clear_minishell(void)
{
	if (g_data.cmd_line != NULL)
	{
		free(g_data.cmd_line);
		g_data.cmd_line = NULL;
	}
	ft_matrix_free(&g_data.splited_cmdl);
	g_data.splited_cmdl = NULL;
	free_env_lst(&g_data.head_env);
	free_token_lst(&g_data.head_token);
	free_cmd_lst(&g_data.head_cmd);
	g_data.is_pipe = false;
	g_data.interrupt_heredoc = false;
}
