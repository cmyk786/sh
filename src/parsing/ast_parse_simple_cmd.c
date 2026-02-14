/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_parse_simple_cmd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 21:26:15 by joloo             #+#    #+#             */
/*   Updated: 2026/02/14 22:09:10 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_internal.h"

int	parse_simple_command(t_token **tok, t_env *env, t_cmd *cmd)
{
	t_redir	*redir;
	t_token	*argv;

	redir = NULL;
	argv = NULL;
	while (*tok != NULL && (is_word(*tok) == TRUE || is_redir(*tok) == TRUE))
	{
		if (is_word(*tok) == TRUE)
		{
			if (parse_word(tok, env, &argv) == FAILURE)
				return (free_redir(&redir), free_tokens(&argv), FAILURE);
		}
		else if (is_redir(*tok) == TRUE)
		{
			if (parse_redir(tok, env, &redir) == FAILURE)
				return (free_redir(&redir), free_tokens(&argv), FAILURE);
		}
	}
	return (ast_new_simple_cmd(redir, argv, cmd));
}

int	parse_word(t_token **tok, t_env *env, t_token **dst)
{
	token_move(tok, dst);
	(void) env;
	return (SUCCESS);
}

int	parse_redir(t_token **tok, t_env *env, t_redir **dst)
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
	node->word = ft_strdup((*tok)->value);
	if (node->word == NULL)
		return (free_redir(&node), FAILURE);
	advance_tok(tok);
	if (node->type == HERE_DOC)
	{
		node->fd = heredoc(node->word, env);
		if (node->fd == -1)
			return (free_redir(&node), FAILURE);
	}
	rediradd_back(dst, node);
	return (SUCCESS);
}
