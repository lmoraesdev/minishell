/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:35:10 by lbatista          #+#    #+#             */
/*   Updated: 2023/03/07 01:43:43 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	MINISHELL_INIT
**	------------
**	DESCRIPTION
**	Initialize values from data struct.
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/
void minishell_init(void)
{
	g_data.head_cmd = NULL;
	g_data.head_env = NULL;
	g_data.cmd_path = NULL;
	g_data.cmd_line = NULL;
	g_data.head_token = NULL;
	g_data.splited_cmdl = NULL;
	g_data.status = 0;
	g_data.is_pipe = false;
	g_data.interrupt_heredoc = false;
}

/*	INIT_EXPAND
**	------------
**	DESCRIPTION
**	Initialize values from exp struct.
**	PARAMETERS
**	1#. The exp struct (exp);
**	2#. The string (str);
**	RETURN VALUES
**	Returns 0
*/
int init_expand(t_expand *exp, char *str)
{
	exp->split = ft_split(str, ' ');
	exp->result = NULL;
	exp->space = false;
	return (0);
}
