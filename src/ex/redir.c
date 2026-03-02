/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 02:34:48 by joloo             #+#    #+#             */
/*   Updated: 2026/03/01 02:34:50 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

static int	apply_redir_in(t_redir *r)
{
	int	fd;

	if (!r->word || !*r->word)
	{
		ft_message("ambiguous redirect\n");
		return (1);
	}
	fd = open(r->word, O_RDONLY);
	if (fd < 0)
	{
		ft_message(r->word);
		ft_message(": ");
		if (errno == ENOENT)
			ft_message("No such file or directory\n");
		else if (errno == EACCES)
			ft_message("Permission denied\n");
		return (1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

static int	apply_redir_out(t_redir *r)
{
	int	fd;

	fd = open(r->word, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		ft_message(r->word);
		ft_message(": ");
		if (errno == EACCES)
			ft_message("Permission denied\n");
		return (1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

static int	apply_append(t_redir *r)
{
	int	fd;

	fd = open(r->word, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		ft_message(r->word);
		ft_message(": ");
		if (errno == EACCES)
			ft_message("Permission denied\n");
		return (1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

static int	apply_here_doc(t_redir *r)
{
	if (r->fd != -1)
	{
		dup2(r->fd, STDIN_FILENO);
		close(r->fd);
	}
	return (0);
}

int	apply_redir(t_ast *node)
{
	t_redir	*r;
	int		val;

	if (!node || !node->simple_cmd.redir)
		return (0);
	r = node->simple_cmd.redir;
	while (r)
	{
		if (r->type == REDIR_IN)
			val = apply_redir_in(r);
		else if (r->type == REDIR_OUT)
			val = apply_redir_out(r);
		else if (r->type == APPEND)
			val = apply_append(r);
		else if (r->type == HERE_DOC)
		{
			if (exp_hd(r, env) == FAILURE)
				return (1);
			val = apply_here_doc(r);
		}
		if (val)
			return (val);
		r = r->next;
	}
	return (0);
}
