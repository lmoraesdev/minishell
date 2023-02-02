/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:44:23 by lbatista          #+#    #+#             */
/*   Updated: 2023/02/02 14:11:30 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	size_t				i;
	unsigned char		*p;

	i = 0;
	p = malloc(n * size);
	if (!p)
		return (0);
	while (i < n * size)
	{
		p[i++] = 0;
	}
	return ((void *)p);
}
