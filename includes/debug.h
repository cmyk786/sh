/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 23:08:05 by joloo             #+#    #+#             */
/*   Updated: 2026/03/07 13:29:29 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

typedef struct s_token	t_token;
typedef struct s_ast	t_ast;

void	print_tokens(t_token *head);
void	print_ast(t_ast *ast);

#endif