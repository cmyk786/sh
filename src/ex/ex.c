/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 02:33:47 by joloo             #+#    #+#             */
/*   Updated: 2026/03/01 02:33:48 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

void	set_fd(int in_fd, int out_fd)
{
	dup2(in_fd, STDIN_FILENO);
	dup2(out_fd, STDOUT_FILENO);
	close(in_fd);
	close(out_fd);
}

int	wait_child(pid_t pid)
{
	int	status;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	waitpid(pid, &status, 0);
	set_sig();
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (1);
}

int	ex(t_ast *node, t_env **env)
{
	int	in_fd;
	int	out_fd;

	in_fd = dup(STDIN_FILENO);
	out_fd = dup(STDOUT_FILENO);
	if (!node)
		return (1);
	if (node->type == SIMPLE_CMD)
		return (ex_cmd(node, env, in_fd, out_fd));
	if (node->type == PIPELINE)
		return (ex_pipe(node, env));
	return (1);
}

int	ex_cmd(t_ast *node, t_env **env, int in_fd, int out_fd)
{
	int		val;
	pid_t	pid;

	if (expn(node, *env, in_fd, out_fd) == 1)
		return (1);
	if (!node->simple_cmd.argv)
		return (0);
	if (is_builtin(node->simple_cmd.argv[0]))
	{
		val = ex_builtin(node, env);
		set_fd(in_fd, out_fd);
		return (val);
	}
	pid = fork();
	if (pid == 0)
		ex_cmd_child(node, env);
	if (pid < 0)
	{
		perror("fork");
		set_fd(in_fd, out_fd);
		return (1);
	}
	set_fd(in_fd, out_fd);
	return (wait_child(pid));
}



