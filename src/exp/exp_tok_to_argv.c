/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_tok_to_argv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:45:10 by joloo             #+#    #+#             */
/*   Updated: 2026/01/22 22:57:27 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp_internal.h"

static int	has_tokens_left(t_token *lst)
{
	while (lst != NULL)
	{
		if (lst->type != DELIMITER)
			return (1);
		lst = lst->next;
	}
	return (0);
}
char	**token_to_argv(t_token *lst)
{
	char	**res;
	int		i;

	i = 0;
	res = ft_calloc(1, sizeof(char *));
	if (res == NULL)
		return (NULL);
	while (lst != NULL && lst->type == DELIMITER)
		lst = lst->next;
	while (lst != NULL)
	{
		if (has_tokens_left(lst) == 1)
		{
			res = ft_realloc(res, 0, i + 1, i + 2);
			if (res == NULL)
				return (NULL);
			// add_words(&lst, &res[i]);
			i++;
		}
		while (lst != NULL && lst->type == DELIMITER)
			lst = lst->next;
	}
	return (res);
}
