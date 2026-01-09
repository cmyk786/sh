/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_exit_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 09:28:55 by joloo             #+#    #+#             */
/*   Updated: 2026/01/08 09:39:44 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_internal.h"

// creates/set key=?
int	env_set_exit_status(t_env **head, int status)
{
	char	*str;

	str = ft_itoa(status);
	if (str == NULL)
		return (FAILURE);
	if (*head == NULL)
	{
		*head = env_node_new(ft_strdup("?"), str);
		if (*head == NULL || (*head)->key == NULL)
			return (FAILURE);
	}
	else
	{
		free((*head)->value);
		(*head)->value = str;
	}
	return (SUCCESS);
}
