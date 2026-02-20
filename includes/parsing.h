/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 19:36:37 by joloo             #+#    #+#             */
/*   Updated: 2026/02/20 23:12:41 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_token		t_token;

typedef enum e_node_type
{
	SIMPLE_CMD,
	PIPELINE,
}	t_node_type;

typedef struct s_heredoc
{
	char	*line;
	int		expand;
}	t_heredoc;

typedef struct s_redir
{
	int				type;
	int				fd;
	union
	{
		char		*word;
		t_heredoc	heredoc;
	};
	struct s_redir	*next;
}	t_redir;

typedef struct s_simple_cmd
{
	t_redir	*redir;
	char	**argv;
}	t_simple_cmd;

typedef struct s_control_op
{
	struct s_ast	*left;
	struct s_ast	*right;
}	t_control_op;

typedef struct s_ast
{
	t_node_type			type;
	union
	{
		t_simple_cmd	simple_cmd;
		t_control_op	control_op;
	};
}	t_ast;

void	free_ast(t_ast **node);
int		parse_ast(t_token *tok, t_ast **root);

#endif