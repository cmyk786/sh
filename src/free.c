/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 22:34:51 by joloo             #+#    #+#             */
/*   Updated: 2026/03/08 11:47:20 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"
#include "env.h"
#include "libft.h"
// free all including env
// use to exit
void	free_exit(t_msh *data, int exit_code)
{
	free_ast(&data->ast);
	free_tokens(&data->tokens);
	free(data->input);
	env_free_all(&data->env);
	exit(exit_code);
}

// free and begins another msh loop
void	free_loop(t_msh *data)
{
	free_ast(&data->ast);
	free_tokens(&data->tokens);
	free(data->input);
	data->input = NULL;
	msh_loop(data);
}
