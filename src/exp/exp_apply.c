/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_apply.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 21:35:31 by joloo             #+#    #+#             */
/*   Updated: 2026/01/30 00:08:16 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp_internal.h"

// apply expansion on tokens based on env
int	exp_apply(t_exp *exp)
{
	t_token	*prev;
	t_token	*curr;
	t_token	*next;

	curr = exp->tok.tokens;
	while (curr != NULL)
	{
		if (curr->type == DQUOTE_VAR || curr->type == UNQUOTE_VAR)
		{
			next = curr->next;
			if (exp_apply_var(exp, &curr) == FAILURE)
				return (FAILURE);
			exp_apply_handle_ptr(exp, prev, curr, next);
			curr = exp->tok.tokens;
			prev = NULL;
			tokenize_print_tokens(curr);
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
	return (SUCCESS);
}

int	exp_apply_var(t_exp *exp, t_token **curr)
{
	t_token	*res;
	char	*value;

	res = NULL;
	value = ft_strdup(env_get(exp->env, (*curr)->value));
	if (value == NULL)
		return (FAILURE);
	if ((*curr)->type == DQUOTE_VAR)
	{
		if (exp_apply_dquote_var(&res, value) == FAILURE)
			return (FAILURE);
	}
	else if ((*curr)->type == UNQUOTE_VAR)
	{
		if (exp_apply_unquote_var(&res, value) == FAILURE)
			return (FAILURE);
	}
	free_token(*curr);
	*curr = res;
	return (SUCCESS);
}

void	exp_apply_handle_ptr(t_exp *exp, t_token *prev, t_token *curr,
				t_token *next)
{
	if (prev == NULL)
		exp->tok.tokens = curr;
	else
		prev->next = curr;
	while (curr != NULL && curr->next != NULL)
		curr = curr->next;
	if (curr != NULL)
		curr->next = next;
}
