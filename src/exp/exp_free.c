/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 20:41:30 by joloo             #+#    #+#             */
/*   Updated: 2026/02/02 14:25:36 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp_internal.h"

void	exp_free(t_exp *exp, char ***argv)
{
	ft_free_str_arr(*argv);
	argv = NULL;
	exp_free_tokens(&exp->tok.tokens);
}

void	exp_free_token(t_token *node)
{
	free(node->value);
	free(node);
}

void	exp_free_tokens(t_token **lst)
{
	t_token	*temp;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		exp_free_token(*lst);
		*lst = temp;
	}
	*lst = NULL;
}
