/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:31:02 by lbatista          #+#    #+#             */
/*   Updated: 2023/02/16 12:31:03 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	BUILTIN_PWD
**	------------
**	DESCRIPTION
**	Builtin pwd.
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/
void builtin_pwd(void)
{
	char *str;

	str = getcwd(NULL, 0);
	printf("%s\n", str);
	free(str);
}
