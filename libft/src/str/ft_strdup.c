/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:11:30 by lbatista          #+#    #+#             */
/*   Updated: 2023/02/02 14:09:38 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t		size;
	char		*new_word;

	size = ft_strlen(s);
	new_word = malloc(sizeof(char) * (size + 1));
	if (!new_word)
		return (NULL);
	size = 0;
	while (s[size] != '\0')
	{
		new_word[size] = s[size];
		size++;
	}
	new_word[size] = '\0';
	return (new_word);
}
