/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_parse_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:34:16 by joloo             #+#    #+#             */
/*   Updated: 2026/02/02 14:15:33 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_internal.h"

t_ast	*parse_command(t_token **tok, t_env *env)
{
	if (*tok != NULL && (is_word(*tok) == TRUE || is_redir(*tok) == TRUE))
		return (parse_simple_command(tok, env));
	return (syntax_err(*tok), NULL);
}
