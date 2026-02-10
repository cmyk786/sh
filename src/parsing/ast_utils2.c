/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 20:51:12 by joloo             #+#    #+#             */
/*   Updated: 2026/02/10 20:58:38 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_internal.h"

int		token_size(t_token *token)
{
	int	i;

	i = 0;
	while (token != NULL)
	{
		i++;
		token = token->next;
	}
	return (i);
}

char	**token_to_arr(t_token *token)
{
	char	**res;
	int		i;

	i = 0;
	res = malloc(sizeof(char *) * (token_size(token) + 1));
	if (res == NULL)
		return (NULL);
	while (token != NULL)
	{
		res[i] = ft_strdup(token->value);
		if (res[i] == NULL)
			return (ft_free_str_arr(res), NULL);
		i++;
		token = token->next;
	}
	res[i] = NULL;
	return (res);
}
