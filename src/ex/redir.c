#include "ex.h"

void    ft_message(char *s)
{
	int	i;

	i = 0;
    if (!s)
        return ;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
}

static int apply_redir_in(t_redir *r)
{
	int fd;

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

static int apply_redir_out(t_redir *r)
{
	int fd;

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

static int apply_dredir_out(t_redir *r)
{
	int fd;

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

static int	apply_dredir_in(t_redir *r)
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
	val = 0;
	while (r)
	{
		if (r->type == TOK_REDIR_IN)
			val = apply_redir_in(r);
		else if (r->type == TOK_REDIR_OUT)
			val = apply_redir_out(r);
		else if (r->type == TOK_DREDIR_OUT)
			val = apply_dredir_out(r);
		else if (r->type == TOK_DREDIR_IN)
			val = apply_dredir_in(r);
		if (val)
			return (val);
		r = r->next;
	}
	return (0);

}
