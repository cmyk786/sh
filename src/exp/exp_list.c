/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 19:44:22 by joloo             #+#    #+#             */
/*   Updated: 2026/02/18 20:33:53 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp_internal.h"

void	exp_tokenadd_back(t_token **head, t_token *new)
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
	new->prev = temp;
}

t_token	*exp_tokenlast(t_token *lst)
{
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

// frees old node
// returns prev of old
t_token	*exp_token_replace(t_token *old, t_token *new)
{
	t_token	*prev;
	t_token	*next;

	prev = old->prev;
	next = old->next;
	exp_free_token(old);
	if (new == NULL)
	{
		prev->next = next;
		if (next != NULL)
			next->prev = prev;
		return (prev);
	}
	prev->next = new;
	new->prev = prev;
	new = exp_tokenlast(new);
	new->next = next;
	if (next != NULL)
		next->prev = new;
	return (prev);
}
