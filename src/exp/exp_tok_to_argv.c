/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_tok_to_argv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:45:10 by joloo             #+#    #+#             */
/*   Updated: 2026/02/27 13:41:38 by joloo            ###   ########.fr       */
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

static char	*add_words(t_token **lst)
{
	char *str;

	str = ft_calloc(1, sizeof(char));
	if (str == NULL)
		return (FAILURE);
	while (*lst != NULL && (*lst)->type != DELIMITER)
	{
		if ((*lst)->type == WORD)
		{
			str = ft_strjoin_free(str, (*lst)->value);
			if (str == NULL)
				return (FAILURE);
		}
		*lst = (*lst)->next;
	}
	return (str);
}

int	token_to_argv(char ***argv, t_token *lst)
{
	char 	**res;
	char	*str;

	res = ft_calloc(1, sizeof(char *));
	if (res == NULL)
		return (FAILURE);
	while (has_words_left(lst) == TRUE)
	{
		while (lst != NULL && lst->type == DELIMITER)
			lst = lst->next;
		if (lst == NULL)
			break ;
		str = add_words(&lst);
		if (str == NULL)
			return (ft_free_str_arr(res), FAILURE);
		res = ft_strarrjoin_free(res, str);
		if (res == NULL)
			return (free(str), FAILURE);
		printf("%s\n", res[0]);
		printf("%p\n", res[1]);
	}
	*argv = res;
	return (SUCCESS);
}
