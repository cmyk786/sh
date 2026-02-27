/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_parse_simple_cmd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:34:50 by joloo             #+#    #+#             */
/*   Updated: 2026/02/27 12:42:03 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_internal.h"

t_ast	*parse_simple_command(t_token **tok)
{
	t_redir	*redir;
	t_token	*argv;

	redir = NULL;
	argv = NULL;
	while (*tok != NULL && (is_word(*tok) == TRUE || is_redir(*tok) == TRUE))
	{
		if (is_word(*tok) == TRUE)
		{
			if (parse_word(tok, &argv) == FAILURE)
				return (free_redir(&redir), free_tokens(&argv), NULL);
		}
		else if (is_redir(*tok) == TRUE)
		{
			if (parse_redir(tok, &redir) == FAILURE)
				return (free_redir(&redir), free_tokens(&argv), NULL);
		}
	}
	return (ast_new_simple_cmd(redir, argv));
}

int	parse_word(t_token **tok, t_token **dst)
{
	t_token	*node;

	node = ft_calloc(1, sizeof(t_token));
	if (node == NULL)
		return (FAILURE);
	node->type = (*tok)->type;
	node->value = ft_strdup((*tok)->value);
	if (node->value == NULL)
		return (free_tokens(&node), FAILURE);
	tokenadd_back(dst, node);
	advance_tok(tok);
	return (SUCCESS);
}

int	parse_redir(t_token **tok, t_redir **dst)
{
	t_redir	*node;

	node = ft_calloc(1, sizeof(t_redir));
	if (node == NULL)
		return (FAILURE);
	node->fd = -1;
	node->type = (*tok)->type;
	advance_tok(tok);
	if (*tok == NULL || is_word(*tok) != TRUE)
		return (syntax_err(*tok), free_redir(&node), FAILURE);
	if (node->type == HERE_DOC)
	{
		if (heredoc(&(node->heredoc), (*tok)->value) == FAILURE)
			return (free_redir(&node), FAILURE);
	}
	else
	{
		node->word = ft_strdup((*tok)->value);
		if (node->word == NULL)
			return (free_redir(&node), FAILURE);
	}
	advance_tok(tok);
	rediradd_back(dst, node);
	return (SUCCESS);
}
