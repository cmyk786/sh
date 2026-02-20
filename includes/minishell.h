/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 22:28:33 by joloo             #+#    #+#             */
/*   Updated: 2026/02/20 22:39:13 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "env.h"
# include "parsing.h"
# include "libft.h"
typedef struct s_msh
{
	char	*input;
	t_env	*env;
	t_token	*tokens;
	t_ast	*ast;
}	t_msh;

void	print_tokens(t_token *head);

void	free_all(t_msh *data);
void	free_part(t_msh *data);

void	msh_loop(t_msh *data);

void	print_ast(t_ast *ast, int depth);

#endif