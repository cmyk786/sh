/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 19:36:37 by joloo             #+#    #+#             */
/*   Updated: 2026/01/04 21:37:42 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "tokenize.h"

typedef enum e_node_type
{
	SIMPLE_CMD,
	PIPELINE,
	AND,
	OR,
	SUBSHELL,
}	t_node_type;

typedef struct s_redir
{
	t_token_type	type;
	int				fd;
	char			*word;
	struct s_redir	*next;
}	t_redir;

typedef struct s_simple_cmd
{
	t_token	*argv;
	t_redir	*redir;
}	t_simple_cmd;

typedef struct s_control_op
{
	struct s_ast	*left;
	struct s_ast	*right;
}	t_control_op;

typedef struct s_subshell
{
	t_ast	*root;
	t_redir	*redir;
}	t_subshell;

typedef struct s_ast
{
	t_node_type			type;
	union
	{
		t_simple_cmd	simple_cmd;
		t_control_op	op;
		t_subshell		subshell;
	};
}	t_ast;

#endif