/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 22:37:13 by joloo             #+#    #+#             */
/*   Updated: 2026/02/20 22:37:24 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_tokens(t_token *head)
{
	t_token	*curr;
	char	*lookup[6];

	curr = head;
	lookup[0] = "HERE_DOC";
	lookup[1] = "APPEND";
	lookup[2] = "REDIR_IN";
	lookup[3] = "REDIR_OUT";
	lookup[4] = "PIPE";
	lookup[5] = "WORD";
	while (curr != NULL)
	{
		printf("type: %s", lookup[curr->type]);
		printf(", value: %s\n", curr->value);
		curr = curr->next;
	}
}
