/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:06:37 by joloo             #+#    #+#             */
/*   Updated: 2026/01/02 20:06:39 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize_internal.h"

void	tokenize_free(t_tok *data)
{
	ft_free_str_arr(data->token_lookup);
	data->token_lookup = NULL;
}

void	free_tokens(t_token **lst)
{
	t_token	*temp;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		free((*lst)->value);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}
