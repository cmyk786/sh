/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_tok_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:40:37 by joloo             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/01/23 12:17:58 by joloo            ###   ########.fr       */
=======
/*   Updated: 2026/02/02 13:34:04 by joloo            ###   ########.fr       */
>>>>>>> origin/AST
/*                                                                            */
/* ************************************************************************** */

#include "exp_internal.h"

t_token	*create_node(char *str, int len, int type)
{
	t_token	*node;

	node = ft_calloc(1, sizeof(t_token));
	if (node == NULL)
		return (FAILURE);
	if (str != NULL)
	{
		node->value = ft_substr(str, 0, len);
		if (node->value == NULL)
		{
			free(node);
			return (NULL);
		}
	}
	node->type = type;
	return (node);
}

<<<<<<< HEAD
void	tokenadd_back(t_token **head, t_token *new)
=======
void	exp_tokenadd_back(t_token **head, t_token *new)
>>>>>>> origin/AST
{
	t_token	*temp;

	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}
