/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:30:54 by joloo             #+#    #+#             */
/*   Updated: 2026/02/05 22:23:58 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc_internal.h"

int	read_stdin(t_hd *data)
{
	char	*line;

	data->buffer = ft_calloc(sizeof(char), 1);
	while (1)
	{
		print_prompt();
		line = get_next_line(0);
		if (line == NULL)
		{
			if (isatty(0) == 1)
				printf("warning: heredoc EOF");
			break ;
		}
		if (check_delimiter(line, data->delimiter) == TRUE)
			break ;
		data->buffer = ft_strjoin_free(data->buffer, line);
		if (data->buffer == NULL)
			return (free(line), FAILURE);
	}
	printf("%s\n", data->buffer);
	if (free_gnl(0) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

void	print_prompt(void)
{
	if (isatty(0) == 1)
		ft_putstr_fd("> ", 1);
}

int	check_delimiter(char *line, char *delimiter)
{
	int	len;

	len = ft_strlen(line);
	if (len == 0)
		return (FALSE);
	if (line[len - 1] != '\n')
		return (FALSE);
	if (ft_strlen(line) - 1 != ft_strlen(delimiter))
		return (FALSE);
	if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) != 0)
		return (FALSE);
	return (TRUE);
}

int	free_gnl(int fd)
{
	int	pipes[2];
	int	temp;

	temp = dup(fd);
	if (pipe(pipes) == -1)
		return (FAILURE);
	dup2(pipes[1], fd);
	get_next_line(fd);
	dup2(temp, fd);
	close(pipes[1]);
	close(pipes[0]);
	close(temp);
	return (SUCCESS);
}
