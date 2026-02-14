/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_parse_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:34:16 by joloo             #+#    #+#             */
/*   Updated: 2026/02/14 22:17:59 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_internal.h"

t_cmd	*parse_command(t_token **tok, t_env *env)
{
	t_cmd	*cmd;

	cmd = ast_new_cmd();
	if (cmd == NULL)
		return (NULL);
	if (*tok != NULL && (is_word(*tok) == TRUE || is_redir(*tok) == TRUE))
	{
		if (parse_simple_command(tok, env, cmd) == FAILURE)
			return (free_cmd(&cmd), NULL);
		return (cmd);
	}
	return (syntax_err(*tok), NULL);
}
