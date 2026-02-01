/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 20:41:30 by joloo             #+#    #+#             */
/*   Updated: 2026/02/01 14:19:08 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp_internal.h"

void	exp_free(t_exp *exp)
{
	free_tokens(&exp->tok.tokens);
}

void	free_token(t_token *node)
{
	free(node->value);
	free(node);
}
void	free_tokens(t_token **lst)
{
	t_token	*temp;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		free_token(*lst);
		*lst = temp;
	}
	*lst = NULL;
}
