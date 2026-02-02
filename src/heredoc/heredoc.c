/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:31:01 by joloo             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/01/30 19:41:32 by joloo            ###   ########.fr       */
=======
/*   Updated: 2026/02/02 13:38:41 by joloo            ###   ########.fr       */
>>>>>>> origin/AST
/*                                                                            */
/* ************************************************************************** */

#include "heredoc_internal.h"

// << should be given a delimiter
// then read the input until a line containing the delimiter is seen.
// However, it doesn’t have to update the history!

// returns fdin of a pipe
// returns -1 on error
int	heredoc(char *delimiter, t_env *env)
{
	t_hd	data;

	ft_memset(&data, 0, sizeof(t_hd));
	data.env = env;
	data.pipe[0] = -1;
	data.pipe[1] = -1;
	data.written = FALSE;
	if (check_quotes(&data, delimiter) == FAILURE)
		return (-1);
	if (read_stdin(&data) == FAILURE)
		return (hd_free(&data), -1);
	if (data.buffer != NULL)
	{
<<<<<<< HEAD
		if (expand(&data) == FAILURE)
=======
		if (hd_expand(&data) == FAILURE)
>>>>>>> origin/AST
			return (hd_free(&data), -1);
	}
	if (write_to_pipe(&data) == FAILURE)
		return (hd_free(&data), -1);
	hd_free(&data);
	return (data.pipe[0]);
}

// check if the delimiter is quoted
int	check_quotes(t_hd *data, char *delimiter)
{
	int	len;

	len = ft_strlen(delimiter);
	if (len >= 2 && ((delimiter[0] == '"' && delimiter[len - 1] == '"')
    			||  (delimiter[0] == '\'' && delimiter[len - 1] == '\'')))
	{
		data->is_quoted = TRUE;
		if (len == 2)
			data->delimiter = ft_strdup("");
		else
			data->delimiter = ft_substr(delimiter, 1, len - 2);
	}
	else
	{
		data->is_quoted = FALSE;
		data->delimiter = ft_strdup(delimiter);
	}
	if (data->delimiter == NULL)
			return (FAILURE);
	return (SUCCESS);
}

// parameter expansion only
<<<<<<< HEAD
int	expand(t_hd *data)
=======
int	hd_expand(t_hd *data)
>>>>>>> origin/AST
{
	if (data->is_quoted == FALSE)
	{
		data->buffer = exp_hd(data->buffer, data->env);
		if (data->buffer == NULL)
			return (FAILURE);
	}
	return (SUCCESS);
}

int	write_to_pipe(t_hd *data)
{
	if (pipe(data->pipe) == -1)
		return (FAILURE);
	if (data->buffer != NULL)
	{
		if (write(data->pipe[1], data->buffer, ft_strlen(data->buffer)) == -1)
			return (FAILURE);
	}
	data->written = TRUE;
	return (SUCCESS);
}

<<<<<<< HEAD
int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	t_env *env = env_init(envp);
	env_set_simple(env, "test=a   a");
	char *line;
	if (argv[1] != NULL)
		line = argv[1];
	else
	{
		ft_putstr_fd("DELIMITER: ", 1);
		line = get_next_line(0);
		line[ft_strlen(line) - 1] = '\0';
	}
	int fd = heredoc(line, env);
	if (fd == -1)
		return (printf("fd = -1\n"), 1);
	printf("RES:\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
	}
	return (0);
}
=======
// int	main(int argc, char **argv, char **envp)
// {
// 	(void) argc;
// 	t_env *env = env_init(envp);
// 	env_set_simple(env, "test=a   a");
// 	char *line;
// 	if (argv[1] != NULL)
// 		line = argv[1];
// 	else
// 	{
// 		ft_putstr_fd("DELIMITER: ", 1);
// 		line = get_next_line(0);
// 		line[ft_strlen(line) - 1] = '\0';
// 	}
// 	int fd = heredoc(line, env);
// 	if (fd == -1)
// 		return (printf("fd = -1\n"), 1);
// 	printf("RES:\n");
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 	}
// 	return (0);
// }
>>>>>>> origin/AST
