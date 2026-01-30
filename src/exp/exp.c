/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:18:10 by joloo             #+#    #+#             */
/*   Updated: 2026/01/30 13:28:49 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp_internal.h"

// performs expansion, word splitting and quote removal
char	**expand(char **argv, t_env *env)
{
	t_exp	exp;
	char	**res;

	if (exp_init(&exp, argv, env) == FAILURE)
		return (exp_free(&exp), NULL);
	if (exp_tok(&exp) == FAILURE)
		return (exp_free(&exp), NULL);
	printf("before apply\n");
	tokenize_print_tokens(exp.tok.tokens);
	if (exp_apply(&exp) == FAILURE)
		return (exp_free(&exp), NULL);
	if (exp.tok.tokens == NULL)
		printf("token null after apply\n");
	printf("after apply\n");
	tokenize_print_tokens(exp.tok.tokens);
	res = token_to_argv(exp.tok.tokens);
	return (res);
}

char	**expand_redir(char *str, t_env *env)
{
	char	**temp;
	char	**res;

	temp = ft_calloc(sizeof(char *), 2));
	if (temp == NULL)
		return (NULL);
	temp[0] = str;
	res = expand(temp, env);
	free(temp);
	return (res);
}

void	tokenize_print_tokens(t_token *head)
{
	t_token	*curr;
	char	*lookup[5];

	curr = head;
	lookup[0] = "DQUOTE_VAR";
	lookup[1] = "UNQUOTE_VAR";
	lookup[2] = "DELIMITER";
	lookup[3] = "QUOTES";
	lookup[4] = "WORD";
	while (curr != NULL)
	{
		printf("type: %s", lookup[curr->type]);
		printf(", value: %s\n", curr->value);
		curr = curr->next;
	}
}

// ./a.out '"$ERM"'
int	main(int argc, char **argv, char **envp)
{
	t_env *env = env_init(envp);
	env_set_simple(env, "test=a   a");
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
	int i = 0;
	while (split[i] != NULL)
	{
		printf("split:%s\n", split[i]);
		i++;
	}
	if (split == NULL)
		printf("INPT EROR");
	char **res = expand(split, env);
	if (res == NULL)
		return (printf("NULL RES\n"), 1);
	i = 0;
	printf("RES:\n");
	while (res[i] != NULL)
	{
		printf("%d, %s\n", i, res[i]);
		i++;
	}
	return (0);
}
