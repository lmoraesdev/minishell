/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_table_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:33:52 by lbatista          #+#    #+#             */
/*   Updated: 2023/03/07 02:15:47 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	FREE_TOKEN_LST
**	------------
**	DESCRIPTION
**	Free all memory allocated within command singly linked list.
**	PARAMETERS
**	#1. The pointer to the first element of the list (head_cmd);
**	RETURN VALUES
**	-
*/
void	free_cmd_lst(t_cmdtable **head_cmd)
{
	t_cmdtable	*temp;

	if (*head_cmd == NULL)
		return ;
	while (*head_cmd != NULL)
	{
		ft_matrix_free(&(*head_cmd)->word);
		ft_matrix_free(&(*head_cmd)->redirect);
		if ((*head_cmd)->err_file)
			free((*head_cmd)->err_file);
		temp = (*head_cmd)->next;
		free(*head_cmd);
		*head_cmd = temp;
	}
	*head_cmd = NULL;
}

/*	CMD_LST_ADD_FRONT
**	------------
**	DESCRIPTION
**	Add the new node at the end of the singly linked list.
**	PARAMETERS
**	#1. The pointer to list (head_cmd);
**	#2. The word array (cmd_v);
**	RETURN VALUES
**	-
*/
void	cmd_lst_add_front(t_cmdtable **head_cmd, t_cmd_value cmd_v)
{
	t_cmdtable	*ptr;
	t_cmdtable	*temp;

	ptr = (t_cmdtable *)malloc(sizeof(t_cmdtable));
	if (!ptr)
		return ;
	ptr->word = cmd_v.word;
	ptr->redirect = cmd_v.redirect;
	ptr->fdin = 0;
	ptr->fdout = 1;
	ptr->err_file = NULL;
	ptr->err_nb = -1;
	if ((*head_cmd) == NULL)
		*head_cmd = ptr;
	else
	{
		temp = *head_cmd;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = ptr;
	}
	ptr->next = NULL;
}
