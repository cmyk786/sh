/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_tok_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:20:08 by joloo             #+#    #+#             */
/*   Updated: 2026/01/22 22:58:09 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp_internal.h"

int	exp_tok_word(t_exp_tok *tok, char *str, int *i)
{
	int		j;
	t_token	*node;

	j = 0;
	while (str[*i + j] != '\0' 
		&& detect_type(tok, str, *i + j) == WORD)
	{
		j++;
	}
	node = create_node(str + *i, j, WORD);
	if (node == NULL)
		return (FAILURE);
	tokenadd_back(&tok->tokens, node);
	*i += j;
	return (SUCCESS);
}
