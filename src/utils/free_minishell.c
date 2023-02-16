/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:34:24 by lbatista          #+#    #+#             */
/*   Updated: 2023/02/16 12:34:36 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	FREE_MINISHELL
**	------------
**	DESCRIPTION
**	Free allocation memory in data struct.
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/
void free_minishell(void)
{
	free_token_lst(&g_data.head_token);
	if (g_data.cmd_line != NULL)
	{
		free(g_data.cmd_line);
		g_data.cmd_line = NULL;
	}
	free_cmd_lst(&g_data.head_cmd);
	ft_matrix_free(&g_data.splited_cmdl);
	g_data.splited_cmdl = NULL;
	g_data.is_pipe = false;
	g_data.interrupt_heredoc = false;
}
