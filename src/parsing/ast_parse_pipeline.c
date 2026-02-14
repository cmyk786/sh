/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_parse_pipeline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 21:23:45 by joloo             #+#    #+#             */
/*   Updated: 2026/02/14 22:32:25 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_internal.h"

static t_pipeline *new_pipeline_lst(void)
{
	t_pipeline	*node;

	node = ft_calloc(1, sizeof(t_pipeline));
	return (node);
}

t_ast	*parse_pipeline(t_token **tok, t_env *env)
{
	t_ast		*node;
	t_pipeline	*pipeline;

	pipeline = new_pipeline_lst();
	if (pipeline == NULL)
		return (NULL);
	pipeline->cmd = parse_command(tok, env);
	if (pipeline->cmd == NULL)
		return (free_pipeline(&pipeline), NULL);
	if (parse_pipeline_tail(tok, env, pipeline) == FAILURE)
		return (NULL);
	node = ast_new_pipeline(pipeline);
	return (node);
}

static void	pipeline_addback(t_pipeline *head, t_pipeline *new)
{
	t_pipeline	*temp;

	temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

int	parse_pipeline_tail(t_token **tok, t_env *env, t_pipeline *node)
{
	t_pipeline	*new;

	if (*tok == NULL)
		return (SUCCESS);
	if (is_pipe(*tok) != TRUE)
		return (SUCCESS);
	new = new_pipeline_lst();
	if (node == NULL)
		return (free_pipeline(&node), FAILURE);
	advance_tok(tok);
	new->cmd = parse_command(tok, env);
	if (new->cmd == NULL)
		return (free_pipeline(&new), free_pipeline(&node), FAILURE);
	pipeline_addback(node, new);
	if (parse_pipeline_tail(tok, env, node) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
