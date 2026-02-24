/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 22:28:22 by joloo             #+#    #+#             */
/*   Updated: 2026/02/23 19:54:00 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
# include "../includes/env.h"
# include "../includes/tokenize.h"
# include "../includes/parsing.h"
# include "../includes/libft.h"
# include "../includes/debug.h"

void	msh_loop(t_msh *data);

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
    	data->input = readline("minishell$");
		if (!data->input)
		{
			printf("exit\n");
			break ;
		}
		if (*data->input)
			add_history(data->input);
    	data->tokens = tokenize(data->input);
    	if (data->tokens == NULL)
      	{
			free_part(data);
			// maybe replace continue with another msh_loop call?
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
