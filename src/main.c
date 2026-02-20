/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 22:28:22 by joloo             #+#    #+#             */
/*   Updated: 2026/02/20 23:04:40 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int    main(int argc, char **argv, char **envp)
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

void	msh_loop(t_msh *data)
{
	while (1)
	{
		// replace with readline
		write (1, "minishell > ", 12);
    	data->input = gnl_safe(0);
    	data->tokens = tokenize(data->input);
    	if (data->tokens == NULL)
      	{
			free_part(data);
			continue ;
		}
    	print_tokens(data->tokens);
    	if (parse_ast(data->tokens, &data->ast) == FAILURE)
     	{
			free_part(data);
			continue ;
		}
    	print_ast(data->ast, 0);
		// execution
		free_part(data);
	}
}
