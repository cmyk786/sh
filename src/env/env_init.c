/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:02:27 by joloo             #+#    #+#             */
/*   Updated: 2026/01/15 13:02:20 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_internal.h"

// converts char **envp to t_env *env
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
		value = extract_value(envp[i]);
		if (key == NULL || value == NULL)
			return (free(key), free(value), env_free_all(&head), NULL);
		if (env_set(head, key, value) == FAILURE)
			return (free(key), free(value), env_free_all(&head), NULL);
		i++;
	}
	return (head);
}

// converts t_env *env to char **envp
char **env_to_arr(t_env *env)
{
	char	**envp;
	int		size;
	int		i;

	env = env->next;
	size = env_size(env);
	envp = ft_calloc(sizeof(char *), (size + 1));
	if (envp == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		envp[i] = ft_strjoin_three(env->key, "=", env->value);
		if (envp[i] == NULL)
			return (ft_free_str_arr(envp), NULL);
		env = env->next;
		i++;
	}
	envp[i] = NULL;
	return (envp);
}
