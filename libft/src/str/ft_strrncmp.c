/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:08:34 by lbatista          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/03/07 02:08:17 by mvavasso         ###   ########.fr       */
=======
/*   Updated: 2023/03/06 21:19:08 by lbatista         ###   ########.fr       */
>>>>>>> 8b31d611841956efd9de3cb745356d37cb701393
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrncmp(const char *s1, const char *s2, size_t len)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;
	int				j;
	int				count;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = ft_strlen(s1) - 1;
	j = ft_strlen(s2) - 1;
	count = 0;
	while (count < len)
	{
		if (str1[i] != str2[j])
		{
			return (0);
		}
		i--;
		j--;
		count++;
	}
	return (1);
}
