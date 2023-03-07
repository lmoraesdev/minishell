/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:46:10 by lbatista          #+#    #+#             */
/*   Updated: 2023/03/07 01:43:11 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	ERROR_MSG_EXIT
**	------------
**	DESCRIPTION
**	Put message error and exit.
**	PARAMETERS
**	#1. The output title (title);
**	#2. The output message (msg);
**	#3. The file descriptor (fd);
**	RETURN VALUES
**	-
*/
void	error_msg_exit(char *title, char *msg, int fd)
{
	put_msg(title, msg, fd);
	exit(EXIT_FAILURE);
}
