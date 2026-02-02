/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_internal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:18:25 by joloo             #+#    #+#             */
/*   Updated: 2026/02/03 01:30:06 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXP_INTERNAL_H
# define EXP_INTERNAL_H

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

# include "libft.h"
# include "../../includes/env.h"

typedef enum e_exp_type
{
	DQUOTE_VAR,
	UNQUOTE_VAR,
	DELIMITER,
	QUOTES,
	WORD,
}	t_exp_type;

typedef struct s_token
{
	char			*value;
	t_exp_type		type;
	struct s_token	*next;
}	t_token;

typedef struct s_exp_tok
{
	char		**argv;
	t_token		*tokens;
	int			in_squote;
	int			in_dquote;
	t_exp_type	type;
}	t_exp_tok;

typedef struct s_exp
{
	t_env		*env;
	t_exp_tok	tok;
}	t_exp;

t_token	*exp_apply_var(t_exp *exp, t_token *curr);
t_token	*exp_apply_dquote_var(char *exp_value);
t_token	*exp_apply_unquote_var(char *exp_value);
int		exp_apply_unquote_var_loop(t_token **res, char *exp_value);
int		exp_apply_unquote_add_word(t_token **res, char *str, int *i);

int		exp_apply(t_exp *exp);
void	exp_apply_handle_ptr(t_exp *exp, t_token *prev, t_token *curr,
				t_token *next);

void	exp_free(t_exp *exp, char ***argv);
void	exp_free_token(t_token *node);
void	exp_free_tokens(t_token **lst);

int		exp_init(t_exp *exp, char **argv, t_env *env);

int		exp_detect_type(t_exp_tok *tok, char *str, int i);

t_token	*create_node(char *str, int len, int type);
void	exp_tokenadd_back(t_token **head, t_token *new);

int		token_to_argv(char ***res, t_token *lst);

int		name_len(char *str);

int		exp_tok_var(t_exp_tok *tok, char *str, int *i);
int		add_delimiter(t_token **tokens);
int		exp_tok_quotes(t_exp_tok *tok, char *str, int *i);
int		exp_tok_word(t_exp_tok *tok, char *str, int *i);

int		exp_tok(t_exp *exp);
int		exp_tok_process(t_exp_tok *tok, char *str);
int		exp_tok_call(t_exp_tok *tok, char *str, int *i);

void	exp_print_tokens(t_token *head);
#endif