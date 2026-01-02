/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:07:21 by joloo             #+#    #+#             */
/*   Updated: 2026/01/02 20:07:41 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize_internal.h"

// parameter is string directly from readline
// returns a linked list of tokens
// returns NULL on error
t_token	*tokenize(char *input)
{
	t_tok	data;
	int		i;

	if (tokenize_init(&data, input) == FAILURE)
		return (NULL);
	i = 0;
	while (1)
	{
		while (data.input[i] != '\0'
			&& ft_isspace(data.input[i]) == TRUE)
			i++;
		if (data.input[i] == '\0')
			break ;
		if (tokenize_add_token(&data, &i) == 0)
		{
			free_tokens(&(data.head));
			tokenize_free(&data);
			return (NULL);
		}
	}
	tokenize_print_tokens(data.head, data.token_lookup);
	tokenize_free(&data);
	return (data.head);
}

int tokenize_add_token(t_tok *data, int *i)
{
	data->type = detect_type(data, *i);
	if (data->type == WORD)
	{
		if (tokenize_add_word(data, i) == FAILURE)
			return (FAILURE);
	}
	else
	{
		if (tokenize_add_operator(data, i) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

// #include <readline/readline.h>
// int	main(void)
// {
// 	char *str = get_next_line(0);
// 	t_token *head = tokenize(str);
// 	if (head == NULL)
// 		return (printf("NULL"), 1);
// 	free_tokens(&head);
// 	free(str);
// 	return (0);
// }
