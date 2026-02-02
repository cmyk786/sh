/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_tok_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 12:17:08 by joloo             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/01/30 00:56:02 by joloo            ###   ########.fr       */
=======
/*   Updated: 2026/02/02 13:34:04 by joloo            ###   ########.fr       */
>>>>>>> origin/AST
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
		node = create_node(str + *i + 1, len, tok->type);
		if (node == NULL)
			return (FAILURE);
		*i += len + 1;
	}
<<<<<<< HEAD
	tokenadd_back(&tok->tokens, node);
=======
	exp_tokenadd_back(&tok->tokens, node);
>>>>>>> origin/AST
	return (SUCCESS);
}

int	add_delimiter(t_token **tokens)
{
	t_token	*node;

	node = create_node(NULL, 0, DELIMITER);
	if (node == NULL)
		return (FAILURE);
<<<<<<< HEAD
	tokenadd_back(tokens, node);
=======
	exp_tokenadd_back(tokens, node);
>>>>>>> origin/AST
	return (SUCCESS);
}

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
<<<<<<< HEAD
	tokenadd_back(&tok->tokens, node);
=======
	exp_tokenadd_back(&tok->tokens, node);
>>>>>>> origin/AST
	*i += 1;
	return (SUCCESS);
}

int	exp_tok_word(t_exp_tok *tok, char *str, int *i)
{
	int		j;
	t_token	*node;

	j = 0;
	while (str[*i + j] != '\0' 
<<<<<<< HEAD
		&& detect_type(tok, str, *i + j) == WORD)
=======
		&& exp_detect_type(tok, str, *i + j) == WORD)
>>>>>>> origin/AST
	{
		j++;
	}
	node = create_node(str + *i, j, WORD);
	if (node == NULL)
		return (FAILURE);
<<<<<<< HEAD
	tokenadd_back(&tok->tokens, node);
=======
	exp_tokenadd_back(&tok->tokens, node);
>>>>>>> origin/AST
	*i += j;
	return (SUCCESS);
}
