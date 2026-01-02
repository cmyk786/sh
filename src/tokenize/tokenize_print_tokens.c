/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_print_tokens.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:06:59 by joloo             #+#    #+#             */
/*   Updated: 2026/01/02 20:07:10 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize_internal.h"

void	tokenize_print_tokens(t_token *head, char **lookup)
{
	t_token	*curr;

	curr = head;
	while (curr != NULL)
	{
		if (lookup[curr->type] == NULL)
			printf("type: WORD");
		else
			printf("type: %s", lookup[curr->type]);
		printf(", value: %s\n", curr->value);
		curr = curr->next;
	}
}
