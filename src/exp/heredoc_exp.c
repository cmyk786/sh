/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_exp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 17:46:57 by joloo             #+#    #+#             */
/*   Updated: 2026/02/20 22:18:57 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp_internal.h"

static int	exp_hd_add_word(char *buffer, char **res, int *i);
static int	exp_hd_add_var(char *buffer, char **res, int *i, t_env *env);

// check if need to expand outside this
char	*exp_hd(char *buffer, t_env *env)
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
				return (free(res), NULL);
		}
		else
		{
			if (exp_hd_add_var(buffer, &res, &i, env) == FAILURE)
				return (free(res), NULL);
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
