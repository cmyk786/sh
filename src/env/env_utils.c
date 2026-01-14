/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:26:47 by joloo             #+#    #+#             */
/*   Updated: 2026/01/14 10:07:51 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_internal.h"

t_env	*find_node(t_env *env, char *key)
{
	while (env != NULL)
	{
		if ((env->key != NULL && key != NULL)
			&& ft_strcmp(env->key, key) == 0)
			return (env);
		env = env->next;
	}
	return (NULL);
}

t_env	*env_node_new(char *key, char *value)
{
	t_env	*new;

	new = ft_calloc(1, sizeof(t_env));
	if (new == NULL)
		return (NULL);
	new->key = key;
	new->value = value;
	return (new);
}

void	env_add_back(t_env **head, t_env *new)
{
	t_env	*temp;

	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}
