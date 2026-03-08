/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 22:37:13 by joloo             #+#    #+#             */
/*   Updated: 2026/03/08 11:47:20 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"
#include "tokenize.h"
#include <stdio.h>

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

void	print_redir_type(int type)
{
	printf("TYPE: ");
	if (type == HERE_DOC)
		printf("HEREDOC");
	if (type == APPEND)
		printf("APPEND");
	if (type == REDIR_IN)
		printf("REDIR_IN");
	if (type == REDIR_OUT)
		printf("REDIR_OUT");
	printf("\n");
}

void	print_redir(t_redir *redir)
{
	while (redir != NULL)
	{
		print_redir_type(redir->type);
		if (redir->type == HERE_DOC)
		{
			printf("EXPAND: %d\n", redir->heredoc.expand);
			printf("HEREDOC LINES:\n%s", redir->heredoc.line);
		}
		else
		{
			printf("WORD: %s\n", redir->word);
		}
		redir = redir->next;
	}
}

void	print_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		printf("ARG: %s\n", argv[i]);
		i++;
	}
}

void	print_ast(t_ast *ast)
{
	if (ast == NULL)
		return ;
	if (ast->type == PIPELINE)
	{
		printf("NODE: PIPELINE\n");
		printf("RIGHT:\n");
		print_ast(ast->control_op.right);
		printf("LEFT:\n");
		print_ast(ast->control_op.left);
	}
	if (ast->type == SIMPLE_CMD)
	{
		print_argv(ast->simple_cmd.argv);
		print_redir(ast->simple_cmd.redir);
	}
}
