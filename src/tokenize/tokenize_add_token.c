/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_add_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:06:20 by joloo             #+#    #+#             */
/*   Updated: 2026/01/02 20:06:22 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize_internal.h"

int	tokenize_add_word(t_tok *data, int *i)
{
	int	j;

	j = 0;
	while (data->input[*i + j] != '\0')
	{
		detect_quotes(data->input[*i + j], &data->in_squote, &data->in_dquote);
		if (data->in_squote == FALSE && data->in_dquote == FALSE)
		{
			if (detect_type(data, *i + j) != WORD)
				break ;
			if (ft_isspace(data->input[*i + j]) == 1)
				break ;
		}
		j++;
	}
	if (j > 0)
	{
		if (add_node(data, *i, j, data->type) == FAILURE)
			return (FAILURE);
		*i += j;
	}
	return (SUCCESS);
}

int	tokenize_add_operator(t_tok *data, int *i)
{
	if (add_node(data, *i,
		ft_strlen(data->token_lookup[data->type]),
		data->type) == FAILURE)
		return (FAILURE);
	*i += ft_strlen(data->token_lookup[data->type]);
	return (SUCCESS);
}

int	add_node(t_tok *data, int start, int len, int type)
{
	t_token	*node;

	node = ft_calloc(1, sizeof(t_token));
	if (node == NULL)
		return (FAILURE);
	node->value = ft_substr(data->input, start, len);
	if (node->value == NULL)
	{
		free(node);
		node = NULL;
		return (FAILURE);
	}
	node->type = type;
	if (data->head == NULL)
	{
		data->head = node;
		data->tail = node;
	}
	else
	{
		data->tail->next = node;
		data->tail = node;
	}
	return (SUCCESS);
}
