/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:36:45 by joloo             #+#    #+#             */
/*   Updated: 2026/02/14 22:42:11 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_internal.h"

t_ast	*ast_new_node(int type)
{
	t_ast	*node;

	node = ft_calloc(1, sizeof(t_ast));
	if (node == NULL)
		return (NULL);
	node->type = type;
	return (node);
}

t_cmd	*ast_new_cmd(void)
{
	t_cmd	*node;

	node = ft_calloc(1, sizeof(t_cmd));
	if (node == NULL)
		return (NULL);
	return (node);
}

int	ast_new_simple_cmd(t_redir *redir, t_token *argv, t_cmd *cmd)
{
	cmd->type = SIMPLE_CMD;
	cmd->simple_cmd.redir = redir;
	if (argv != NULL)
	{
		cmd->simple_cmd.argv = token_to_arr(argv);
		if (cmd->simple_cmd.argv == NULL)
			return (free_tokens(&argv), FAILURE);
	}
	free_tokens(&argv);
	return (SUCCESS);
}
