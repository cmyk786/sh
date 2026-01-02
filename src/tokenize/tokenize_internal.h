/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:06:48 by joloo             #+#    #+#             */
/*   Updated: 2026/01/02 20:06:49 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_INTERNAL_H
# define TOKENIZE_INTERNAL_H

# include "tokenize.h"
# include "libft.h"

# ifndef SUCCESS
#  define SUCCESS 1
# endif

# ifndef FAILURE
#  define FAILURE 0
# endif

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

typedef struct s_tok
{
	char	*input;
	t_token	*head;
	t_token	*tail;
	int		type;
	char	**token_lookup;
	int		in_squote;
	int		in_dquote;
}	t_tok;

int		tokenize_add_word(t_tok *data, int *i);
int		tokenize_add_operator(t_tok *data, int *i);
int		add_node(t_tok *data, int start, int len, int type);

void	detect_quotes(char c, int *in_squote, int *in_dquote);
int		detect_type(t_tok *data, int i);

void	tokenize_free(t_tok *data);

int		tokenize_init(t_tok *data, char *input);
int		init_lookup(t_tok *data);

void	tokenize_print_tokens(t_token *head, char **lookup);
int 	tokenize_add_token(t_tok *data, int *i);
#endif