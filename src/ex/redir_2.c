/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 02:34:48 by joloo             #+#    #+#             */
/*   Updated: 2026/03/01 02:34:50 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

void	get_hd(t_redir *r)
{
	int	pipe_fd[2];

	if (r->heredoc.line)
	{
		if (pipe(pipe_fd) == -1)
		{
			perror("pipe");
			return (1);
		}
		write(pipe_fd[1], r->heredoc.line, ft_strlen(r->heredoc.line));
		close(pipe_fd[1]);
		r->fd = pipe_fd[0];
	}
}
