/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_apply.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 21:35:31 by joloo             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/01/31 14:12:51 by joloo            ###   ########.fr       */
=======
/*   Updated: 2026/02/02 13:36:18 by joloo            ###   ########.fr       */
>>>>>>> origin/AST
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

void	exp_apply_handle_ptr(t_exp *exp, t_token *prev, t_token *curr,
				t_token *next)
{
	if (exp->tok.type == UNQUOTE_VAR && curr->value[0] == '\0')
	{
		if (prev == NULL)
			exp->tok.tokens = next;
		else
			prev->next = next;
<<<<<<< HEAD
		free_token(curr);
=======
		exp_free_token(curr);
>>>>>>> origin/AST
		exp->tok.type = WORD;
	}
	else
	{
		if (prev == NULL)
			exp->tok.tokens = curr;
		else
			prev->next = curr;
		while (curr != NULL && curr->next != NULL)
			curr = curr->next;
		curr->next = next;
	}
}
