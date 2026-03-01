/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 02:34:12 by joloo             #+#    #+#             */
/*   Updated: 2026/03/01 02:34:14 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

t_env	*copy_env_node(t_env *env)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	node->key = ft_strdup(env->key);
	if (!node->key)
	{
		free(node);
		return (NULL);
	}
	node->value = ft_strdup(env->value);
	if (!node->value)
	{
		free(node->key);
		free(node);
		return (NULL);
	}
	node->next = NULL;
	return (node);
}

t_env	*copy_env(t_env *env)
{
	t_env	*copy;
	t_env	*node;
	t_env	*list;

	copy = NULL;
	list = NULL;
	while (env)
	{
		node = copy_env_node(env);
		if (!node)
			return (NULL);
		if (!copy)
		{
			list = node;
			copy = node;
		}
		else
		{
			copy->next = node;
			copy = copy->next;
		}
		env = env->next;
	}
	return (list);
}

void	sort_env(t_env *env)
{
	char	*tmp_key;
	char	*tmp_val;
	t_env	*tmp;

	if (!env)
		return ;
	while (env->next)
	{
		tmp = env->next;
		while (tmp)
		{
			if (ft_strcmp(env->key, tmp->key) > 0)
			{
				tmp_key = env->key;
				env->key = tmp->key;
				tmp->key = tmp_key;
				tmp_val = env->value;
				env->value = tmp->value;
				tmp->value = tmp_val;
			}
			tmp = tmp->next;
		}
		env = env->next;
	}
}
