/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 02:33:41 by joloo             #+#    #+#             */
/*   Updated: 2026/03/01 02:33:42 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

static void	ex_pipe_left(t_ast *node, t_env **env, int *pipefd)
{
	set_sig_child();
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	exit(ex(node->control_op.left, env));
}

static void	ex_pipe_right(t_ast *node, t_env **env, int *pipefd)
{
	set_sig_child();
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	exit(ex(node->control_op.right, env));
}

static int	ex_pipe_parent(int *pipefd, pid_t left, pid_t right)
{
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(left, NULL, 0);
	return (wait_child(right));
}

int	ex_pipe(t_ast *node, t_env **env)
{
	int		pipefd[2];
	pid_t	left_pid;
	pid_t	right_pid;

	if (pipe(pipefd) < 0)
		return (perror("pipe"), 1);
	left_pid = fork();
	if (left_pid < 0)
		return (perror("fork"), 1);
	if (left_pid == 0)
		ex_pipe_left(node, env, pipefd);
	right_pid = fork();
	if (right_pid < 0)
		return (perror("fork"), 1);
	if (right_pid == 0)
		ex_pipe_right(node, env, pipefd);
	return (ex_pipe_parent(pipefd, left_pid, right_pid));
}
