/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:41:20 by lbatista          #+#    #+#             */
/*   Updated: 2023/02/22 11:41:22 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	SYNTAX_ERROR
**	------------
**	DESCRIPTION
**	Output message and set exit code.
**	PARAMETERS
**	#1. The output message (msg);
**	RETURN VALUES
**	Return 1
*/
int syntax_error(char *msg)
{
	put_msg("minishell", msg, 2);
	g_data.status = 2;
	return (1);
}
