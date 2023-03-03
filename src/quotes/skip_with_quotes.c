/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_with_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:43:15 by lbatista          #+#    #+#             */
/*   Updated: 2023/03/03 17:54:31 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	SKIP_QUOTES
**	------------
**	DESCRIPTION
**	Checks the type of quotes and skips to the closing quotes.
**	PARAMETERS
**	#1. The pointer of command line (cmd);
**	RETURN VALUES
**	-
*/
void	skip_quotes(char **cmd)
{
	int	quote_type;

	quote_type = is_quote_type(**cmd);
	if (quote_type != -1)
	{
		(*cmd)++;
		while (**cmd && **cmd != quote_type)
			(*cmd)++;
	}
	return ;
}
