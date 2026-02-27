/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 22:28:33 by joloo             #+#    #+#             */
/*   Updated: 2026/02/27 16:27:30 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_env	t_env;
typedef struct s_token	t_token;
typedef struct s_ast	t_ast;

typedef struct s_msh
{
	char	*input;
	t_env	*env;
	t_token	*tokens;
	t_ast	*ast;
}	t_msh;

void	msh_loop(t_msh *data);
void	free_exit(t_msh *data, int exit_code);
void	free_loop(t_msh *data);

#endif