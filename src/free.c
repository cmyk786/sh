/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 22:34:51 by joloo             #+#    #+#             */
/*   Updated: 2026/02/27 12:38:00 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/parsing.h"
#include "../includes/env.h"
#include "libft.h"
// free all including env
// use when exit
void	free_all(t_msh *data)
{
	free_part(data);
	env_free_all(&data->env);
}

// free to begin another msh loop
void	free_part(t_msh *data)
{
	free_ast(&data->ast);
	free_tokens(&data->tokens);
	free(data->input);
	data->input = NULL;
}
