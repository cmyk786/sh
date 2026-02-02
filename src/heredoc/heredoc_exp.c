/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_exp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 17:46:57 by joloo             #+#    #+#             */
/*   Updated: 2026/02/03 01:37:17 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc_internal.h"

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

int	exp_hd_add_word(char *buffer, char **res, int *i)
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

// name (bash)
// A word consisting solely of letters, numbers, and 
// underscores and beginning with a letter or underscore.
// returns the len of a valid name
static int	name_len(char *str)
{
	int	i;

	if (str[0] == '\0')
		return (0);
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

int	exp_hd_add_var(char *buffer, char **res, int *i, t_env *env)
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
