/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:41:28 by joloo             #+#    #+#             */
/*   Updated: 2026/02/27 17:56:45 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_internal.h"

// skip over key=?
// does not print NULL
void	env_print(t_env *head)
{
	head = head->next;
	while (head != NULL)
	{
		printf("%s=%s\n", head->key, head->value);
		head = head->next;
	}
}
