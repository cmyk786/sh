/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_apply.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 21:35:31 by joloo             #+#    #+#             */
/*   Updated: 2026/02/18 20:58:20 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp_internal.h"

// apply expansion on tokens based on env
int	exp_apply(t_exp *exp)
{
	t_token	*curr;

	curr = exp->tok.tokens;
	while (curr != NULL)
	{
		if (curr->type == DQUOTE_VAR || curr->type == UNQUOTE_VAR)
		{
			if (exp_apply2(exp, &curr) == FAILURE)
				return (FAILURE);
		}
		else
			curr = curr->next;
	}
	return (SUCCESS);
}

// value = "" for unquoted is removed
int	exp_apply2(t_exp *exp, t_token **curr)
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
			return (exp_free_tokens(&res), free(value), FAILURE);
	}
	else if ((*curr)->type == UNQUOTE_VAR)
	{
		if (value[0] != '\0')
		{
			if (exp_apply_unquote_var(&res, value) == FAILURE)
				return (exp_free_tokens(&res), free(value), FAILURE);
		}
	}
	*curr = exp_token_replace(*curr, res);
	free(value);
	return (SUCCESS);
}
