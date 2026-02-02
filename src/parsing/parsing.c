/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:38:18 by joloo             #+#    #+#             */
/*   Updated: 2026/02/02 14:18:44 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_internal.h"

int	parse_ast(t_token *tok, t_env *env, t_ast **root)
{
	t_token *temp;

	temp = tok;
	*root = ast_new(&temp, env);
	if (*root == NULL)
		return (FAILURE);
	return (SUCCESS);
}
static int	free_gnl(int fd)
{
	int	pipes[2];
	int	temp;

	temp = dup(fd);
	if (pipe(pipes) == -1)
		return (FAILURE);
	dup2(pipes[1], fd);
	get_next_line(fd);
	dup2(temp, fd);
	close(pipes[1]);
	close(pipes[0]);
	close(temp);
	return (SUCCESS);
}

static void	print_tokens(t_token *head)
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

int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	t_env *env = env_init(envp);
	env_set_simple(env, "test=a   a");
	char *line;
	if (argv[1] != NULL)
		line = argv[1];
	else
	{
		line = get_next_line(0);
		free_gnl(0);
	}
	t_token *tok;
	tok = tokenize(line);
	if (tok == NULL)
		return (printf("tok NULL\n"), 1);
	print_tokens(tok);
	t_ast *root = NULL;
	if (parse_ast(tok, env, &root) == FAILURE)
		return (printf("parse_ast fail\n"), 1);
	print_ast(root, 0);
	return (0);
}

