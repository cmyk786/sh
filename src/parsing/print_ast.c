
// ai generated
#include "parsing_internal.h"

/* helpers */

void	print_indent(int depth)
{
	while (depth > 0)
	{
		printf("  ");
		depth--;
	}
}

/* redirections */

void	print_redir(t_redir *redir, int depth)
{
	while (redir)
	{
		print_indent(depth);
		printf("REDIR type=%d fd=%d word=%s\n",
			redir->type,
			redir->fd,
			redir->word);
		redir = redir->next;
	}
}

/* argv */

void	print_argv(char **argv, int depth)
{
	int i = 0;
	while (argv[i] != NULL)
	{
		print_indent(depth);
		printf("ARG %s\n", argv[i]);
		i++;
	}
}

/* AST */

void print_ast(t_ast *ast, int depth)
{
	t_pipeline *pipe;

	if (ast == NULL)
		return;

	print_indent(depth);

	if (ast->type == CMD)
	{
		printf("SIMPLE_CMD\n");
		print_argv(ast->cmd->simple_cmd.argv, depth + 1);
		print_redir(ast->cmd->simple_cmd.redir, depth + 1);
	}
	else if (ast->type == PIPELINE)
	{
		printf("PIPELINE\n");
		pipe = ast->pipeline;
		while (pipe)
		{
			print_indent(depth + 1);
			printf("PIPE_ELEMENT\n");
			print_argv(pipe->cmd->simple_cmd.argv, depth + 2);
			print_redir(pipe->cmd->simple_cmd.redir, depth + 2);
			pipe = pipe->next;
		}
	}
}
