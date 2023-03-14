/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itohex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:12:39 by lbatista          #+#    #+#             */
/*   Updated: 2023/03/14 20:39:51 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*n_convert(char *str, size_t size, unsigned long int num,
	const char format)
{
	int	result;

	str[size] = '\0';
	while (size--)
	{
		result = num % 16;
		if (9 < result || result < 16)
			str[size] = result + 87;
		if (result < 10)
			str[size] = result + 48;
		num /= 16;
	}
	if (format == 'X')
		strtoupper(str);
	return (str);
}

static size_t	nb_size(unsigned long int num)
{
	size_t	len;

	len = 1;
	num /= 16;
	while (num)
	{
		num /= 16;
		len++;
	}
	return (len);
}

int	itohex(unsigned long int n, const char format)
{
	size_t	n_digits;
	char	*str;

	n_digits = nb_size(n);
	str = malloc(sizeof(char) * (n_digits + 1));
	if (str == NULL)
		return (0);
	ft_putstr_fd(n_convert(str, n_digits, n, format), 1);
	free(str);
	return (n_digits);
}
