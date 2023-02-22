/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:26:55 by lbatista          #+#    #+#             */
/*   Updated: 2023/02/22 13:27:05 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	CHECK_CMD
**	------------
**	DESCRIPTION
**	Checks if the cmd received from the terminal exists in the PATH variable.
**	PARAMETERS
**	#1. The command array (word);
**	RETURN VALUES
**	-
*/
void check_cmd(char **word)
{
	char **path_list;
	char *aux;
	int i;

	g_data.path_value = search_env_value("PATH");
	if (g_data.path_value != NULL)
	{
		path_list = ft_split(g_data.path_value, ':');
		aux = ft_strcat("/", word[0]);
		i = 0;
		while (path_list[i])
		{
			g_data.cmd_path = ft_strcat(path_list[i], aux);
			if ((access(g_data.cmd_path, F_OK) == 0))
			{
				break;
			}
			free(g_data.cmd_path);
			g_data.cmd_path = NULL;
			i++;
		}
		free(aux);
		ft_matrix_free(&path_list);
	}
}
