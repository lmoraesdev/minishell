/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:45:46 by lbatista          #+#    #+#             */
/*   Updated: 2023/03/07 01:43:16 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	COLORED_LOGIN
**	------------
**	DESCRIPTION
**	Creates the colored login line.
**	PARAMETERS
**	#1. The username (user);
**	#2. The hostname (hostname);
**	RETURN VALUES
**	Returns the login line (user@hostname:) as a string
*/
char	*colored_login(char **user, char **hostname)
{
	char	*login;
	char	*colon;
	char	*colored_login;
	char	*final_login;

	login = ft_strcat(*user, *hostname);
	colored_login = ft_strcat(CYN, login);
	colon = ft_strcat(RESET, ":");
	final_login = ft_strcat(colored_login, colon);
	free(login);
	free(colored_login);
	free(colon);
	free(*user);
	free(*hostname);
	return (final_login);
}

/*	COLORED_PROMPT_LINE
**	------------
**	DESCRIPTION
**	Creates the colored prompt line.
**	PARAMETERS
**	#1. The login line -user@hostname:- (login);
**	RETURN VALUES
**	Returns the colored prompt line (user@hostname:cwd$ ) as a string
*/
char	*colored_prompt_line(char **login)
{
	char	*cwd;
	char	aux[1024];
	char	*colored_aux;
	char	*dollar;
	char	*prompt_line;

	getcwd(aux, sizeof(aux));
	colored_aux = ft_strcat(MAG, aux);
	dollar = ft_strcat(RESET, "$ ");
	cwd = ft_strcat(colored_aux, dollar);
	prompt_line = ft_strcat(*login, cwd);
	free(cwd);
	free(*login);
	free(colored_aux);
	free(dollar);
	return (prompt_line);
}
