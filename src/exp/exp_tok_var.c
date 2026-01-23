/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_tok_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:09:49 by joloo             #+#    #+#             */
/*   Updated: 2026/01/22 22:57:46 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp_internal.h"

int	exp_tok_var(t_exp_tok *tok, char *str, int *i)
{
	int	len;
	t_token	*node;

	len = name_len(str + *i + 1);
	if (len == 0)
	{
		node = create_node("$", 1, WORD);
		if (node == NULL)
			return (FAILURE);
		*i += 1;
	}
	else
	{
		node = create_node(str + *i, len + 1, tok->type);
		if (node == NULL)
			return (FAILURE);
		*i += len + 1;
	}
	tokenadd_back(&tok->tokens, node);
	return (SUCCESS);
}
