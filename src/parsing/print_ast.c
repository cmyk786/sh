
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

void print_redir(t_redir *redir, int depth)
{
	while (redir)
	{
		print_indent(depth);
		if (redir->type == HERE_DOC)
		{
			printf("REDIR type=%d fd=%d heredoc.line=%s expand=%d\n",
				redir->type,
				redir->fd,
				redir->heredoc.line,
				redir->heredoc.expand);
		}
		else
		{
			printf("REDIR type=%d fd=%d word=%s\n",
				redir->type,
				redir->fd,
				redir->word);
		}
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

void	print_ast(t_ast *ast, int depth)
{
	if (ast == NULL)
		return ;

	print_indent(depth);

	if (ast->type == SIMPLE_CMD)
	{
		printf("SIMPLE_CMD\n");
		print_argv(ast->simple_cmd.argv, depth + 1);
		print_redir(ast->simple_cmd.redir, depth + 1);
	}
	else if (ast->type == PIPELINE)
	{
		printf("PIPELINE\n");

		print_indent(depth);
		printf("LEFT:\n");
		print_ast(ast->control_op.left, depth + 1);

		print_indent(depth);
		printf("RIGHT:\n");
		print_ast(ast->control_op.right, depth + 1);
	}
}
