/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:24:38 by joloo             #+#    #+#             */
/*   Updated: 2026/01/07 16:01:04 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_internal.h"

void	env_free_node(t_env *node)
{
	free(node->key);
	free(node->value);
	free(node);
}

void	env_free_all(t_env **head)
{
	t_env	*temp;

	while (*head != NULL)
	{
		temp = (*head)->next;
		env_free_node(*head);
		*head = temp;
	}
	*head = NULL;
}
