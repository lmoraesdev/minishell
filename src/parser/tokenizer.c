/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   takenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:42:08 by lbatista          #+#    #+#             */
/*   Updated: 2023/02/22 11:42:10 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	TOKENIZER
**	------------
**	DESCRIPTION
**	Create tokens from the command line using space as a separator.
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/
void tokenizer(void)
{
	g_data.splited_cmdl = split_cmd(g_data.cmd_line);
}
