/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:16:59 by joloo             #+#    #+#             */
/*   Updated: 2026/02/01 22:14:50 by joloo            ###   ########.fr       */
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

// moves src to back of dst and advances src
void	token_move(t_token **src, t_token **dst)
{
	t_token	*temp;

	temp = *src;
	advance_tok(src);
	temp->next = NULL;
	tokenadd_back(dst, temp);
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
