/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_apply.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 21:35:31 by joloo             #+#    #+#             */
/*   Updated: 2026/01/30 00:55:28 by joloo            ###   ########.fr       */
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
	prev = NULL;
	while (curr != NULL)
	{
		if (curr->type == DQUOTE_VAR || curr->type == UNQUOTE_VAR)
		{
			next = curr->next;
			curr = exp_apply_var(exp, curr);
			if (curr == NULL)
				return (FAILURE);
			exp_apply_handle_ptr(exp, prev, curr, next);
			curr = exp->tok.tokens;
			prev = NULL;
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
	return (SUCCESS);
}

t_token	*exp_apply_var(t_exp *exp, t_token *curr)
{
	t_token	*res;
	char	*value;

	res = NULL;
	printf("%s\n", curr->value);
	value = ft_strdup(env_get(exp->env, curr->value));
	if (value == NULL)
        return (NULL);
	if (curr->type == DQUOTE_VAR)
	{
		res = exp_apply_dquote_var(value);
	}
	else if (curr->type == UNQUOTE_VAR)
	{
		res = exp_apply_unquote_var(value);
	}
	free_token(curr);
	tokenize_print_tokens(res);
	return (res);
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
	curr->next = next;
}
