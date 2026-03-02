/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_ex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 02:33:47 by joloo             #+#    #+#             */
/*   Updated: 2026/03/01 02:33:48 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

static int	expand_redirs(t_redir *r, t_env *env)
{
	while (r)
	{
		if (r->type != HEREDOC)
		{
			if (expand_redir(&r->word, env) == FAILURE)
				return (FAILURE);
		}
		r = r->next;
	}
	return (SUCCESS);
}

int	exp(t_ast *node, t_env *env, int in_fd, int out_fd)
{
	if (expand_redirs(node->simple_cmd.redir, env) == 1)
		return (1);
	if (expand(&node->simple_cmd.argv, env) == 1)
		return (1);
	if (apply_redir(node) == 1)
	{
		set_fd(in_fd, out_fd);
		return (1);
	}
	return (0);
}
