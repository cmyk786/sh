/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:02:27 by joloo             #+#    #+#             */
/*   Updated: 2026/01/09 18:30:17 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_internal.h"

t_env	*env_init(char **envp)
{
	int		i;
	char	*key;
	char	*value;
	t_env	*head;

	i = 0;
	head = NULL;
	if (env_set_exit_status(&head, 0) == FAILURE)
		return (env_free_all(&head), NULL);
	while (envp[i] != NULL)
	{
		key = extract_key(envp[i]);
		if (key == NULL)
			return (env_free_all(&head), NULL);
		value = extract_value(envp[i]);
		if (value == NULL)
			return (free(key), env_free_all(&head), NULL);
		if (env_set(head, key, value) == FAILURE)
		{
			free(key);
			free(value);
			return (env_free_all(&head), NULL);
		}
		i++;
	}
	return (head);
}
