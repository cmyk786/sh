/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_tok_to_argv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:45:10 by joloo             #+#    #+#             */
/*   Updated: 2026/01/30 00:53:16 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp_internal.h"

static int	has_words_left(t_token *lst)
{
	while (lst != NULL)
	{
		if (lst->type == WORD)
			return (TRUE);
		lst = lst->next;
	}
	return (FALSE);
}

static int	add_words(t_token **lst, char **res)
{
	*res = ft_calloc(1, sizeof(char));
	if (*res == NULL)
		return (FAILURE);
	while (*lst != NULL && (*lst)->type != DELIMITER)
	{
		if ((*lst)->type == WORD)
		{
			*res = ft_strjoin_free(*res, (*lst)->value);
			if (*res == NULL)
				return (FAILURE);
		}
		*lst = (*lst)->next;
	}
	return (SUCCESS);
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
		if (has_words_left(lst) == TRUE)
		{
			res = ft_realloc(res, 0,
				sizeof(char *) * (i + 1), sizeof(char *) * (i + 2));
			if (res == NULL)
				return (NULL);
			if (add_words(&lst, &(res[i])) == FAILURE)
				return (ft_free_str_arr(res), NULL);
			i++;
		}
		while (lst != NULL && lst->type == DELIMITER)
			lst = lst->next;
	}
	res[i] = NULL;
	return (res);
}
