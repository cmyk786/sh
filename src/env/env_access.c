/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_access.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:02:24 by joloo             #+#    #+#             */
/*   Updated: 2026/01/14 10:06:57 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_internal.h"

// returns value from key node
// if no existing key node, return empty string
// do not free returned string
char	*env_get(t_env *env, char *key)
{
	t_env	*node;

	node = find_node(env, key);
	if (node != NULL)
	{
		return (node->value);
	}
	else
	{
		return ("");
	}
}

// if key node exists, changes key nodes value
// else creates new key node with value
int	env_set(t_env *env, char *key, char *value)
{
	t_env	*node;

	node = find_node(env, key);
	if (node != NULL)
	{
		free(node->value);
		node->value = value;
	}
	else
	{
		node = env_node_new(key, value);
		if (node == NULL)
			return (FAILURE);
		env_add_back(&env, node);
	}
	return (SUCCESS);
}

// str is "key=value"
// using extract_key and extract_value
// use env_set for more complex cases
int	env_set_simple(t_env *env, char *str)
{
	char	*key;
	char	*value;

	key = extract_key(str);
	value = extract_value(str);
	if (key == NULL || value == NULL)
		return (free(key), free(value), FAILURE);
	return (env_set(env, key, value));
}

// for unset, removes key node if available
void	env_unset(t_env *env, char *key)
{
	t_env	*prev;

	prev = env;
	env = env->next;
	while (env != NULL)
	{
		if ((env->key != NULL && key != NULL)
			&& ft_strcmp(env->key, key) == 0)
		{
			prev->next = env->next;
			env_free_node(env);
			return ;
		}
		prev = env;
		env = env->next;
	}
}
