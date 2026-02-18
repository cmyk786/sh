/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:18:10 by joloo             #+#    #+#             */
/*   Updated: 2026/02/18 21:08:13 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp_internal.h"

// performs expansion, word splitting and quote removal
int	expand(char ***argv, t_env *env)
{
	t_exp	exp;
	char	**res;

	if (exp_init(&exp, *argv, env) == FAILURE)
		return (exp_free(&exp, argv), FAILURE);
	if (exp_tok(&exp) == FAILURE)
		return (exp_free(&exp, argv), FAILURE);
	if (exp_apply(&exp) == FAILURE)
		return (exp_free(&exp, argv), FAILURE);
	if (token_to_argv(&res, exp.tok.tokens) == FAILURE)
		return (exp_free(&exp, argv), FAILURE);
	exp_free(&exp, argv);
	*argv = res;
	return (SUCCESS);
}

int	expand_redir(char ***res, char *str, t_env *env)
{
	*res = ft_calloc(sizeof(char *), 2);
	if (*res == NULL)
		return (FAILURE);
	(*res)[0] = str;
	if (expand(res, env) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

void	exp_print_tokens(t_token *head)
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
// int	main(int argc, char **argv, char **envp)
// {
// 	t_env *env = env_init(envp);
// 	env_set_simple(env, "test=a   a");
// 	char **split;
// 	if (argv[1] != NULL)
// 		split = ft_split(argv[1], ' ');
// 	else
// 	{
// 		char *line = gnl_safe(0);
// 		split = ft_split(line	, ' ');
// 		free(line);
// 	}
// 	(void) argc;
// 	int i = 0;
// 	while (split[i] != NULL)
// 	{
// 		printf("split:%s\n", split[i]);
// 		i++;
// 	}
// 	if (split == NULL)
// 		printf("INPT EROR");
// 	if (expand(&split, env) == FAILURE)
// 		return (printf("expand failure\n"), 1);
// 	i = 0;
// 	char **res = split;
// 	printf("RES:\n");
// 	if (res == NULL)
// 		return (printf("NULL RES\n"), 0);
// 	while (res[i] != NULL)
// 	{
// 		printf("%d, ", i);
// 		if (res[i][0] == '\0')
// 			printf("empty string\n");
// 		else
// 			printf("%s\n", res[i]);
// 		i++;
// 	}
// 	env_free_all(&env);
// 	ft_free_str_arr(res);
// 	return (0);
// }
