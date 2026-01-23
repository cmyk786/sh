/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_tok_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:40:37 by joloo             #+#    #+#             */
/*   Updated: 2026/01/22 22:33:51 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp_internal.h"

int	add_delimiter(t_token **tokens)
{
	t_token	*node;

	node = create_node(NULL, 0, DELIMITER);
	if (node == NULL)
		return (FAILURE);
	tokenadd_back(tokens, node);
	return (SUCCESS);
}

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

void	tokenadd_back(t_token **head, t_token *new)
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
