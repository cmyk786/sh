/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:16:59 by joloo             #+#    #+#             */
/*   Updated: 2026/02/27 15:00:09 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_internal.h"

void	advance_tok(t_token **tok)
{
	*tok = (*tok)->next;
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

void	rediradd_back(t_redir **head, t_redir *new)
{
	t_redir	*temp;

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
