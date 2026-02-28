/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 22:28:22 by joloo             #+#    #+#             */
/*   Updated: 2026/02/27 16:28:07 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/env.h"
#include "../includes/tokenize.h"
#include "../includes/parsing.h"
#include "../includes/libft.h"
#include "../includes/debug.h"
#include "../src/ex/ex.h"

int	s = 0;

int	main(int argc, char **argv, char **envp)
{
	t_msh	data;

	(void) argc;
	(void) argv;
	ft_memset(&data, 0, sizeof(t_msh));
	data.env = env_init(envp);
	env_set_simple(data.env, "test=a   a");
	msh_loop(&data);
	return (0);
}

static void	msh_parse(t_msh *data)
{
	data->tokens = tokenize(data->input);
	if (data->tokens == NULL)
	{
		printf("Tokenizer FAILURE\n");
		free_loop(data);
	}
	print_tokens(data->tokens);
	if (parse_ast(data->tokens, &data->ast) == FAILURE)
	{
		printf("Parsing FAILURE\n");
		free_loop(data);
	}
	print_ast(data->ast, 0);
}

void	msh_loop(t_msh *data)
{
	set_sig();
	data->input = readline("minishell$");
	if (!data->input)
	{
		printf("exit\n");
		free_exit(data, 0);
	}
	if (*data->input)
		add_history(data->input);
	msh_parse(data);
	ex(data->ast, &data->env);
	free_loop(data);
}
