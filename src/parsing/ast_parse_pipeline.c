/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_parse_pipeline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:08:12 by joloo             #+#    #+#             */
/*   Updated: 2026/02/03 01:30:35 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_internal.h"

t_ast	*parse_pipeline(t_token **tok, t_env *env)
{
	t_ast	*node;

	node = parse_command(tok, env);
	if (node == NULL)
		return (NULL);
	return (parse_pipeline_tail(tok, env, node));
}

t_ast	*parse_pipeline_tail(t_token **tok, t_env *env, t_ast *left)
{
	t_ast	*right;
	t_ast	*node;

	if (*tok == NULL)
		return (left);
	if (is_pipe(*tok) != TRUE)
		return (left);
	advance_tok(tok);
	right = parse_command(tok, env);
	if (right == NULL)
		return (free_ast(&left), NULL);
	node = ast_new_control(left, right, PIPELINE);
	if (node == NULL)
		return (free_ast(&left), free_ast(&right), NULL);
	return (parse_pipeline_tail(tok, env, node));
}
