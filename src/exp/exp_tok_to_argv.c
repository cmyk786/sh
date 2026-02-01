/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_tok_to_argv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:45:10 by joloo             #+#    #+#             */
/*   Updated: 2026/02/01 15:13:59 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp_internal.h"

static int	has_words_left(t_token *lst)
{
	while (lst != NULL)
	{
		if (lst->type == WORD || lst->type == QUOTES)
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

int	token_to_argv(char ***res, t_token *lst)
{
	int		i;

	*res = NULL;
	i = 0;
	while (has_words_left(lst) == TRUE)
	{
		while (lst != NULL && lst->type == DELIMITER)
			lst = lst->next;
		if (lst == NULL)
			break ;
		*res = ft_realloc(*res, 0,
			sizeof(char *) * (i + 1), sizeof(char *) * (i + 2));
		if (*res == NULL)
			return (FAILURE);
		(*res)[i + 1] = NULL; 
		if (add_words(&lst, &((*res)[i])) == FAILURE)
			return (ft_free_str_arr(*res), FAILURE);
		i++;

	}
	return (SUCCESS);
}
