/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:18:10 by joloo             #+#    #+#             */
/*   Updated: 2026/01/23 12:14:42 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp_internal.h"

// performs expansion, word splitting and quote removal
char	**expand(char **argv, t_env *env)
{
	t_exp	exp;

	if (exp_init(&exp, argv, env) == FAILURE)
		return (exp_free(&exp), NULL);
	if (exp_tok(&exp) == FAILURE)
		return (exp_free(&exp), NULL);
	tokenize_print_tokens(exp.tok.tokens);
	return (0);
}

void	tokenize_print_tokens(t_token *head)
{
	t_token	*curr;

	curr = head;
	while (curr != NULL)
	{
		printf("type: %d", curr->type);
		printf(", value: %s\n", curr->value);
		curr = curr->next;
	}
}

// ./a.out '"$ERM"'
int	main(int argc, char **argv)
{
	t_env *env = NULL;
	char **split;
	if (argv[1] != NULL)
		split = ft_split(argv[1], ' ');
	else
	{
		char *line = get_next_line(0);
		line[ft_strlen(line) - 1] = '\0';
		split = ft_split(line	, ' ');
	}
	(void) argc;
	if (split == NULL)
		printf("INPT EROR");
	expand(split, env);
	return (0);
}
