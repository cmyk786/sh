/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_exp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 17:46:57 by joloo             #+#    #+#             */
/*   Updated: 2026/03/07 18:21:55 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "env.h"
#include "parsing.h"

static char	*exp_hd_apply(char *buffer, t_env *env);
static int	exp_hd_add_word(char *buffer, char **res, int *i);
static int	exp_hd_add_var(char *buffer, char **res, int *i, t_env *env);

int	exp_hd(t_redir *node, t_env *env)
{
	int	fd[2];

	if (node->heredoc.expand == TRUE)
	{
		node->heredoc.line = exp_hd_apply(node->heredoc.line, env);
		if (node->heredoc.line == NULL)
			return (FAILURE);
	}
	if (pipe(fd) == -1)
		return (FAILURE);
	if (write(fd[1], node->heredoc.line,
			ft_strlen(node->heredoc.line)) == -1)
		return (close(fd[0]), close(fd[1]), FAILURE);
	node->fd = fd[0];
	close(fd[1]);
	return (SUCCESS);
}

static char	*exp_hd_apply(char *buffer, t_env *env)
{
	char	*res;
	int		i;

	res = ft_calloc(sizeof(char), 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] != '$')
		{
			if (exp_hd_add_word(buffer, &res, &i) == FAILURE)
				return (free(res), free(buffer), NULL);
		}
		else
		{
			if (exp_hd_add_var(buffer, &res, &i, env) == FAILURE)
				return (free(res), free(buffer), NULL);
		}
	}
	free(buffer);
	return (res);
}

static int	exp_hd_add_word(char *buffer, char **res, int *i)
{
	int	len;

	len = ft_strchr_pos(buffer + *i, '$');
	if (len == 0)
		len = ft_strlen(buffer + *i);
	else
		len--;
	*res = ft_strnjoin_free(*res, buffer + *i, len);
	if (*res == NULL)
		return (FAILURE);
	*i += len;
	return (SUCCESS);
}

static int	name_len(char *str)
{
	int	i;

	if (str[0] == '\0')
		return (0);
	if (str[0] == '?')
		return (1);
	if (ft_isalpha(str[0]) != 1 && str[0] != '_')
		return (0);
	i = 1;
	while (str[i] != '\0'
		&& (ft_isalpha(str[i]) == 1
			|| ft_isdigit(str[i]) == 1
			|| str[i] == '_'))
	{
		i++;
	}
	return (i);
}

static int	exp_hd_add_var(char *buffer, char **res, int *i, t_env *env)
{
	char	*value;
	char	*key;
	int		len;

	(*i)++;
	len = name_len(buffer + *i);
	if (len == 0)
	{
		*res = ft_strjoin_free(*res, "$");
		if (*res == NULL)
			return (FAILURE);
		return (SUCCESS);
	}
	key = ft_substr(buffer, *i, len);
	if (key == NULL)
		return (FAILURE);
	value = env_get(env, key);
	*res = ft_strjoin_free(*res, value);
	if (*res == NULL)
		return (free(key), FAILURE);
	*i += len;
	return (free(key), SUCCESS);
}
