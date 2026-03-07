/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 01:31:16 by joloo             #+#    #+#             */
/*   Updated: 2026/03/07 19:46:22 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_INTERNAL_H
# define PARSING_INTERNAL_H

# include "parsing.h"
# include "libft.h"
# include "tokenize.h"

int		is_redir(t_token *tok);
int		is_pipe(t_token *tok);
int		is_word(t_token *tok);

void	free_redir(t_redir **node);

t_ast	*ast_new_control(t_ast *left, t_ast *right, int type);
t_ast	*ast_new_simple_cmd(t_redir *redir, t_token *argv);

t_ast	*parse_command(t_token **tok);

int		heredoc(t_heredoc *heredoc, char *raw_delim);
int		hd_check_quotes(t_heredoc *heredoc, char *raw_delim, char **delim);
int		hd_read_stdin(t_heredoc *heredoc, char *delim);
int		hd_read_stdin2(t_heredoc *heredoc, char *delim);
int		hd_check_delim(char *line, char *delim);

t_ast	*parse_pipeline(t_token **tok);
t_ast	*parse_pipeline_tail(t_token **tok, t_ast *left);

t_ast	*parse_simple_command(t_token **tok);
int		parse_word(t_token **tok, t_token **dst);
int		parse_redir(t_token **tok, t_redir **dst);

void	advance_tok(t_token **tok);
void	tokenadd_back(t_token **head, t_token *new);
void	rediradd_back(t_redir **head, t_redir *new);

int		token_size(t_token *token);
char	**token_to_arr(t_token *token);
void	set_sig_h(void);
void	set_sig(void);
t_ast	*ast_new(t_token **tok);

void	syntax_err(t_token *tok);
#endif
