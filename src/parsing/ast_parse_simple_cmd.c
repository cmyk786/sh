/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_parse_simple_cmd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:34:50 by joloo             #+#    #+#             */
/*   Updated: 2026/02/02 00:20:28 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_internal.h"

t_ast	*parse_simple_command(t_token **tok, t_env *env)
{
	t_ast	*node;

	node = ast_new_simple_cmd();
	if (node == NULL)
		return (NULL);
	while (*tok != NULL && (is_word(*tok) == TRUE || is_redir(*tok) == TRUE))
	{
		if (is_word(*tok) == TRUE)
		{
			if (parse_word(tok, env, &node->simple_cmd.argv) == FAILURE)
				return (free_ast(&node), NULL);
		}
		else if (is_redir(*tok) == TRUE)
		{
			if (parse_redir(tok, env, &node->simple_cmd.redir) == FAILURE)
				return (free_ast(&node), NULL);
		}
	}
	return (node);
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
	if (node->type == HERE_DOC)
	{
		node->fd = heredoc(node->word, env);
		if (node->fd == -1)
			return (free_redir(&node), FAILURE);
	}
	rediradd_back(dst, node);
	return (SUCCESS);
}
