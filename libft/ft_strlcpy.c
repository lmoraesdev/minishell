/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:14:58 by lbatista          #+#    #+#             */
/*   Updated: 2023/02/02 14:03:41 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	leng;
	size_t	new_size;

	leng = 0;
	new_size = size - 1;
	if (size)
	{
		while (*src && new_size--)
		{
			*dest = *(unsigned char *)src;
			dest++;
			src++;
			leng++;
		}
		*dest = '\0';
	}
	while (*src)
	{
		leng++;
		src++;
	}
	return (leng);
}
