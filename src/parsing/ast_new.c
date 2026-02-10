/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:36:45 by joloo             #+#    #+#             */
/*   Updated: 2026/02/10 21:00:08 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_internal.h"

t_ast	*ast_new_control(t_ast *left, t_ast *right, int type)
{
	t_ast	*node;

	node = ft_calloc(1, sizeof(t_ast));
	if (node == NULL)
		return (NULL);
	node->control_op.left = left;
	node->control_op.right = right;
	node->type = type;
	return (node);
}

t_ast	*ast_new_simple_cmd(t_redir *redir, t_token *argv)
{
	t_ast	*node;

	node = ft_calloc(1, sizeof(t_ast));
	if (node == NULL)
		return (NULL);
	node->simple_cmd.redir = redir;
	if (argv != NULL)
	{
		node->simple_cmd.argv = token_to_arr(argv);
		if (node->simple_cmd.argv == NULL)
			return (free_ast(&node), free_tokens(&argv), NULL);
	}
	node->type = SIMPLE_CMD;
	free_tokens(&argv);
	return (node);
}
