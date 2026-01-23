/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_tok_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:05:56 by joloo             #+#    #+#             */
/*   Updated: 2026/01/22 22:56:54 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp_internal.h"

// modifies in_squote && in_dquote
// returns TRUE on modification of quoted state
static int	detect_quotes(char c, int *in_squote, int *in_dquote)
{
	if (c == '\'' && *in_dquote == 0)
	{
		if (*in_squote == 0)
			*in_squote = 1;
		else
			*in_squote = 0;
		return (TRUE);
	}
	if (c == '\"' && *in_squote == 0)
	{
		if (*in_dquote == 0)
			*in_dquote = 1;
		else
			*in_dquote = 0;
		return (TRUE);
	}
	return (FALSE);
}

int	exp_tok_quotes(t_exp_tok *tok, char *str, int *i)
{
	t_token	*node;

	if (detect_quotes(str[*i], &tok->in_squote, &tok->in_dquote) != TRUE)
		return (SUCCESS);
	if (str[*i] == '\'')
		node = create_node("\'", 1, QUOTES);
	else if (str[*i] == '\"')
		node = create_node("\"", 1, QUOTES);
	if (node == NULL)
		return (FAILURE);
	tokenadd_back(&tok->tokens, node);
	*i += 1;
	return (SUCCESS);
}

