/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:07:40 by joloo             #+#    #+#             */
/*   Updated: 2026/02/27 14:56:26 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_internal.h"

void	free_ast(t_ast **node)
{
	if (node == NULL || *node == NULL)
		return ;
	if ((*node)->type == PIPELINE)
	{
		free_ast(&(*node)->control_op.right);
		free_ast(&(*node)->control_op.left);
	}
	else if ((*node)->type == SIMPLE_CMD)
	{
		free_redir(&(*node)->simple_cmd.redir);
		ft_free_str_arr((*node)->simple_cmd.argv);
	}
	free(*node);
	*node = NULL;
}

void	free_redir(t_redir **node)
{
	if (node == NULL || *node == NULL)
		return ;
	free_redir(&(*node)->next);
	if ((*node)->type == HERE_DOC)
		free((*node)->heredoc.line);
	else
		free((*node)->word);
	free(*node);
	*node = NULL;
}
