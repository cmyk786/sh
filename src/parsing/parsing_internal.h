
#ifndef PARSING_INTERNAL_H
# define PARSING_INTERNAL_H

# include "../../includes/parsing.h"
# include "libft.h"
# include "../../includes/env.h"
# include "../../includes/heredoc.h"
# include "../../includes/tokenize.h"

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

int		is_redir(t_token *tok);
int		is_pipe(t_token *tok);
int		is_word(t_token *tok);

void	free_redir(t_redir **node);

t_ast	*ast_new_control(t_ast *left, t_ast *right, int type);
t_ast	*ast_new_simple_cmd(void);

t_ast	*parse_command(t_token **tok, t_env *env);

t_ast	*parse_pipeline(t_token **tok, t_env *env);
t_ast	*parse_pipeline_tail(t_token **tok, t_env *env, t_ast *left);

t_ast	*parse_simple_command(t_token **tok, t_env *env);
int		parse_word(t_token **tok, t_env *env, t_token **dst);
int		parse_redir(t_token **tok, t_env *env, t_redir **dst);

void	advance_tok(t_token **tok);
void	tokenadd_back(t_token **head, t_token *new);
void	token_move(t_token **src, t_token **dst);
void	rediradd_back(t_redir **head, t_redir *new);

t_ast	*ast_new(t_token **tok, t_env *env);

int		parse_ast(t_token *tok, t_env *env, t_ast **root);

void	print_ast(t_ast *ast, int depth);

void	syntax_err(t_token *tok);
#endif