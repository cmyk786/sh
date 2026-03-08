/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_parse_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:30:54 by joloo             #+#    #+#             */
/*   Updated: 2026/02/20 22:18:17 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_internal.h"

// << should be given a delim
// then read the input until a line containing the delim is seen.
// However, it doesn’t have to update the history!

// only reads, doesnt expand
int	heredoc(t_heredoc *heredoc, char *raw_delim)
{
	char	*delim;

	if (hd_check_quotes(heredoc, raw_delim, &delim) == FAILURE)
		return (FAILURE);
	if (hd_read_stdin(heredoc, delim) == FAILURE)
		return (free(delim), FAILURE);
	free(delim);
	return (SUCCESS);
}

// check if the delim is quoted
int	hd_check_quotes(t_heredoc *heredoc, char *raw_delim, char **delim)
{
	int	len;

	len = ft_strlen(raw_delim);
	if (len >= 2 && ((raw_delim[0] == '"' && raw_delim[len - 1] == '"')
			|| (raw_delim[0] == '\'' && raw_delim[len - 1] == '\'')))
	{
		heredoc->expand = FALSE;
		if (len == 2)
			*delim = ft_strdup("");
		else
			*delim = ft_substr(raw_delim, 1, len - 2);
	}
	else
	{
		heredoc->expand = TRUE;
		*delim = ft_strdup(raw_delim);
	}
	if (delim == NULL)
		return (FAILURE);
	return (SUCCESS);
}

int	hd_read_stdin(t_heredoc *heredoc, char *delim)
{
	set_sig_h();
	g_s = 0;
	heredoc->line = ft_calloc(sizeof(char), 1);
	if (heredoc->line == NULL)
		return (FAILURE);
	if (hd_read_stdin2(heredoc, delim) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	hd_read_stdin2(t_heredoc *heredoc, char *delim)
{
	char	*line;

	while (1)
	{
		if (isatty(0) == 1)
			ft_putstr_fd("> ", 1);
		line = gnl_safe(0);
		if (g_s == 130)
			return (free(line), set_sig(), FAILURE);
		if (line == NULL)
		{
			ft_putstr_fd("warning: heredoc EOF\n", 2);
			break ;
		}
		if (hd_check_delim(line, delim) == TRUE)
			break ;
		heredoc->line = ft_strjoin_free(heredoc->line, line);
		if (heredoc->line == NULL)
			return (free(line), FAILURE);
		free(line);
	}
	return (SUCCESS);
}

// frees line if TRUE cause line limit
int	hd_check_delim(char *line, char *delim)
{
	int	len;

	len = ft_strlen(line);
	if (len == 0)
		return (FALSE);
	if (line[len - 1] != '\n')
		return (FALSE);
	if (ft_strlen(line) - 1 != ft_strlen(delim))
		return (FALSE);
	if (ft_strncmp(line, delim, ft_strlen(delim)) != 0)
		return (FALSE);
	free(line);
	return (TRUE);
}
