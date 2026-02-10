static void	set_fd(int in_fd, int out_fd)
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
	signal(SIGINT, sig_prompt);
    if (WIFEXITED(status))
        return (WEXITSTATUS(status));
    if (WIFSIGNALED(status))
        return (128 + WTERMSIG(status));
    return (1);
}

int ex(t_ast *node, t_env **env)
{
    if (!node)
        return (1);
    if (node->type == SIMPLE_CMD)
        return (ex_cmd(node, env));
    if (node->type == PIPELINE)
        return (ex_pipe(node, env));
    return (1);
}

int	ex_cmd(t_ast *node, t_env **env)
{
    int		*in_fd;
    int		*out_fd;
    int		val;
    pid_t	pid;

    *in_fd = dup(STDIN_FILENO);
    *out_fd = dup(STDOUT_FILENO);
    if (apply_redir(node) == 1)
    {
		set_fd(in_fd, out_fd);
		return (1);
    }
	if (is_builtin(argv[0]))
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
