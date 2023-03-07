/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:44:31 by lbatista          #+#    #+#             */
/*   Updated: 2023/03/07 02:10:26 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	IS_QUOTE_TYPE
**	------------
**	DESCRIPTION
**	Check character is simple quote or double quote.
**	PARAMETERS
**	#1. The character (ch);
**	RETURN VALUES
**	Return 39 if the char is in single quotes, 34 for double quotes
**	and -1 if dont have quotes.
*/
int	is_quote_type(char ch)
{
	if (ch == S_QUOTE)
		return (S_QUOTE);
	if (ch == D_QUOTE)
		return (D_QUOTE);
	return (-1);
}

/*	VALIDATE_QUOTE_CLOSED
**	------------
**	DESCRIPTION
**	Check for unclosed quotes.
**	PARAMETERS
**	-
**	RETURN VALUES
**	Return true if the quotes are closed and false if aren't not.
*/
bool	validate_quote_closed(void)
{
	int		quote_type;
	bool	quote_closed;
	char	*cmd_line;

	quote_closed = true;
	cmd_line = g_data.cmd_line;
	while (*cmd_line)
	{
		if (quote_closed)
		{
			quote_type = is_quote_type(*cmd_line);
			if (quote_type != -1)
				quote_closed = false;
		}
		else if (*cmd_line == quote_type)
			quote_closed = true;
		cmd_line++;
	}
	return (quote_closed);
}
