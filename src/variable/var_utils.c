/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:32:46 by lbatista          #+#    #+#             */
/*   Updated: 2023/02/16 12:32:48 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	IS_EQUAL_SIGN
**	------------
**	DESCRIPTION
**	Check the command line is a variable declaration.
**	PARAMETERS
**	#1. The pointers to command line (cmd);
**	RETURN VALUES
**	Return true if command line is variable declaration and false if it's not.
*/
bool is_equal_sign(char *cmd)
{
	if (ft_strchr(cmd, '=') == NULL)
		return (false);
	return (true);
}
