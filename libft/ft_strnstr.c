/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:17:50 by lbatista          #+#    #+#             */
/*   Updated: 2023/02/02 14:03:10 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	leng;

	leng = ft_strlen(little);
	if (little[0] == '\0')
		return ((char *)big);
	while (*big && leng <= len--)
	{
		if (ft_strncmp(big, little, leng) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
