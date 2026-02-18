/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_tok_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:40:37 by joloo             #+#    #+#             */
/*   Updated: 2026/02/17 21:38:09 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp_internal.h"

t_token	*create_node(char *str, int len, int type)
{
	t_token	*node;

	node = ft_calloc(1, sizeof(t_token));
	if (node == NULL)
		return (FAILURE);
	if (str != NULL)
	{
		node->value = ft_substr(str, 0, len);
		if (node->value == NULL)
		{
			free(node);
			return (NULL);
		}
	}
	node->type = type;
	return (node);
}
