/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_tok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 14:01:35 by joloo             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/01/22 22:48:14 by joloo            ###   ########.fr       */
=======
/*   Updated: 2026/02/02 13:32:59 by joloo            ###   ########.fr       */
>>>>>>> origin/AST
/*                                                                            */
/* ************************************************************************** */

#include "exp_internal.h"

int	exp_tok(t_exp *exp)
{
	int	i;

	i = 0;
	while (exp->tok.argv[i] != NULL)
	{
		exp->tok.in_squote = 0;
		exp->tok.in_dquote = 0;
		if (exp_tok_process(&exp->tok, exp->tok.argv[i]) == FAILURE)
			return (FAILURE);
		if (add_delimiter(&exp->tok.tokens) == FAILURE)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	exp_tok_process(t_exp_tok *tok, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
<<<<<<< HEAD
		tok->type = detect_type(tok, str, i);
=======
		tok->type = exp_detect_type(tok, str, i);
>>>>>>> origin/AST
		if (exp_tok_call(tok, str, &i) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

int	exp_tok_call(t_exp_tok *tok, char *str, int *i)
{
	if (tok->type == QUOTES)
	{
		if (exp_tok_quotes(tok, str, i) == FAILURE)
			return (FAILURE);
	}
	else if (tok->type == DQUOTE_VAR || tok->type == UNQUOTE_VAR)
	{
		if (exp_tok_var(tok, str, i) == FAILURE)
			return (FAILURE);
	}
	else if (tok->type == WORD)
	{
		if (exp_tok_word(tok, str, i) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}
