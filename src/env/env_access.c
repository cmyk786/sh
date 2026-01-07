/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_access.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:02:24 by joloo             #+#    #+#             */
/*   Updated: 2026/01/07 17:32:10 by joloo            ###   ########.fr       */
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
		return (node->value);
	else
		return ("");
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

// for unset, removes key node if available
void	env_remove(t_env *env, char *key)
{
	t_env	*prev;

	while (env != NULL)
	{
		if (ft_strcmp(env->key, key) == 0)
		{
			prev->next = env->next;
			env_free_node(env);
		}
		prev = env;
		env = env->next;
	}
}
