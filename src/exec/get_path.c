/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:28:50 by lbatista          #+#    #+#             */
/*   Updated: 2023/02/22 13:28:51 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	GET_PATH
**	------------
**	DESCRIPTION
**	Loops through the environment list and look for the variable value.
**	PARAMETERS
**	#1. The name of the env var (var);
**	RETURN VALUES
**	Returns the string of the variable value
*/
char *search_env_value(char *var)
{
	t_env *ptr;

	ptr = g_data.head_env;
	while (ptr != NULL)
	{
		if (strcmp_eq(var, ptr->name))
			return (ptr->value);
		ptr = ptr->next;
	}
	return (NULL);
}
