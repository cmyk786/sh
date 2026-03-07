/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 02:34:59 by joloo            #+#    #+#             */
/*   Updated: 2026/03/01 02:35:01 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

static t_env	*free_node(t_env *node)
{
	t_env	*tmp;

	tmp = node->next;
	free(node->key);
	free(node->value);
	free(node);
	return (tmp);
}

static void	remove_env_node(t_env **env, char *key)
{
	t_env	*node;
	t_env	*prev;

	node = (*env)->next;
	prev = NULL;
	while (node)
	{
		if (!ft_strcmp(key, node->key))
		{
			if (prev)
				prev->next = node->next;
			else
				*env = node->next;
			node = free_node(node);
		}
		else
		{
			prev = node;
			node = node->next;
		}
	}
}

int	unset(char **a, t_env **env)
{
	int	i;

	i = 1;
	if (!a[i])
		return (0);
	while (a[i])
	{
		remove_env_node(env, a[i]);
		i++;
	}
	return (0);
}

void	ft_message(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		return ;
	}
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
}
