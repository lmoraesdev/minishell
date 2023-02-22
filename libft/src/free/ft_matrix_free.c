/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:57:37 by lbatista          #+#    #+#             */
/*   Updated: 2023/02/22 12:57:49 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	FT_MATRIX_FREE
**	------------
**	DESCRIPTION
**	Free all memory allocated within matrix.
**	PARAMETERS
**	#1. The pointer to array of strings (matrix);
**	RETURN VALUES
**	-
*/
void ft_matrix_free(char ***matrix)
{
	int i;

	i = 0;
	if (!(*matrix))
		return;
	while ((*matrix)[i])
	{
		free((*matrix)[i]);
		i++;
	}
	free(*matrix);
	*matrix = NULL;
	return;
}
