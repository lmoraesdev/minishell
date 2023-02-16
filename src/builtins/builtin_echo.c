/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:30:32 by lbatista          #+#    #+#             */
/*   Updated: 2023/02/16 12:30:33 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	BUILTIN_ECHO
**	------------
**	DESCRIPTION
**	Displays the arguments passed to standard output..
**	PARAMETERS
**	#1. The content to be displayed (word);
**	RETURN VALUES
**	-
*/
void builtin_echo(char **word)
{
	int i;

	i = 1;
	while (strcmp_eq(word[i], "-n"))
		i++;
	while (word[i] != NULL)
	{
		ft_printf("%s", word[i]);
		if (word[i + 1] != NULL)
			ft_printf(" ");
		i++;
	}
	if (!strcmp_eq(word[1], "-n"))
		ft_printf("\n");
}
