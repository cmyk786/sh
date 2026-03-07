/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 22:28:22 by joloo             #+#    #+#             */
/*   Updated: 2026/03/07 21:20:27 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/env.h"
#include "../includes/tokenize.h"
#include "../includes/parsing.h"
#include "../includes/libft.h"
#include "../includes/debug.h"
#include "../src/ex/ex.h"

int	g_s = 0;

int	main(int argc, char **argv, char **envp)
{
	t_msh	data;

	(void) argc;
	(void) argv;
	ft_memset(&data, 0, sizeof(t_msh));
	data.env = env_init(envp);
	msh_loop(&data);
	return (0);
}

static void	msh_parse(t_msh *data)
{
	int	debug;

	debug = 0;
	data->tokens = tokenize(data->input);
	if (data->tokens == NULL)
	{
		ft_putstr_fd("Tokenize failure", 2);
		free_loop(data);
	}
	if (debug == 1)
		print_tokens(data->tokens);
	if (parse_ast(data->tokens, &data->ast) == FAILURE)
	{
		free_loop(data);
	}
	free(data->input);
	data->input = NULL;
	free_tokens(&data->tokens);
	if (debug == 1)
		print_ast(data->ast);
}

void	msh_loop(t_msh *data)
{
	set_sig();
	data->input = readline("minishell$ ");
	if (!data->input)
	{
		printf("exit\n");
		free_exit(data, 0);
	}
	if (*data->input)
		add_history(data->input);
	msh_parse(data);
	g_s = ex(data->ast, &data->env);
	env_set_exit_status(&data->env, g_s);
	free_loop(data);
}

// THE README.MD
// # Module Assignments  
// Readline input - yiwei  
// Signals - yiwei  
// Tokenizer/Lexer - joloo  
// Heredoc - joloo  
// Parsing - joloo  
// Environment variables - joloo  
// Environment variable expansion - joloo  
// Execution - yiwei  
// Built-ins - yiwei  

// # Parser BNF
// ```
// <pipeline>      ::= <command> <pipeline-tail>

// <pipeline-tail>  ::= ε
//                   | <PIPE> <command> <pipeline-tail>

// <command>        ::= <simple-command>

// NOTE:
// simple-command elements are stored in linked lists

// <simple-command> ::= <redirection> <simple-command-tail>
//                    | <word>    <simple-command-tail>

// <simple-command-tail> ::= ε
//                         | <redirection> <simple-command-tail>
//                         | <word>    <simple-command-tail>

// <redirection> 		  ::= <redirection-operator> <word>
// ```
