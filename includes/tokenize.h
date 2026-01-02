/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:13:41 by joloo             #+#    #+#             */
/*   Updated: 2026/01/02 20:13:42 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

// here_doc = <<
// append = >>
// redir_in = <
// redir_out = >
// pipe = |
typedef enum e_token_type
{
	HERE_DOC,
	APPEND,
	REDIR_IN,
	REDIR_OUT,
	PIPE,
	WORD,
}	t_token_type;

typedef struct s_token
{
	char			*value;
	t_token_type	type;
	struct s_token	*next;
}	t_token;

t_token	*tokenize(char *input);
void	free_tokens(t_token **head);

#endif