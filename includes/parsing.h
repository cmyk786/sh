/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 19:36:37 by joloo             #+#    #+#             */
/*   Updated: 2026/02/14 21:56:18 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "tokenize.h"

typedef enum e_node_type
{
	CMD,
	PIPELINE,
}	t_node_type;

typedef enum e_cmd_type
{
	SIMPLE_CMD,
}	t_cmd_type;

typedef struct s_redir
{
	t_token_type	type;
	int				fd;
	char			*word;
	struct s_redir	*next;
}	t_redir;

typedef struct s_simple_cmd
{
	t_redir	*redir;
	char	**argv;
}	t_simple_cmd;

typedef struct s_cmd
{
	t_cmd_type		type;
	union
	{
		t_simple_cmd simple_cmd;
	};
}	t_cmd;

typedef struct s_pipeline
{
	t_cmd				*cmd;
	struct s_pipeline	*next;
}	t_pipeline;

typedef struct s_ast
{
	t_node_type		type;
	union
	{
		t_cmd		*cmd;
		t_pipeline	*pipeline;
	};
}	t_ast;

void	free_ast(t_ast **node);

#endif