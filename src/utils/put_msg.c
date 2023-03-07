/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:35:44 by lbatista          #+#    #+#             */
/*   Updated: 2023/03/07 01:43:47 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	PUT_MSG
**	------------
**	DESCRIPTION
**	Put message in 'title: description' format.
**	PARAMETERS
**	#1. The output title (title);
**	#2. The output message (msg);
**	#3. The file descriptor (fd);
**	RETURN VALUES
**	-
*/
void	put_msg(char *title, char *msg, int fd)
{
	ft_putstr_fd(title, fd);
	ft_putstr_fd(": ", fd);
	ft_putendl_fd(msg, fd);
	return ;
}

/*	PUT_MSG_CMD
**	------------
**	DESCRIPTION
**	Put message in 'title: cmd: description' format.
**	PARAMETERS
**	#1. The output title (title);
**	#2. The output cmd (cmd);
**	#3. The output description (msg);
**	#4. The file descriptor (fd);
**	RETURN VALUES
**	-
*/
void	put_msg_cmd(char *title, char *cmd, char *msg, int fd)
{
	ft_putstr_fd(title, fd);
	ft_putstr_fd(": ", fd);
	ft_putstr_fd(cmd, fd);
	ft_putstr_fd(": ", fd);
	ft_putendl_fd(msg, fd);
	return ;
}
