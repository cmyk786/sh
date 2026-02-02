/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_check_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:47:37 by joloo             #+#    #+#             */
/*   Updated: 2026/02/01 22:04:08 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_internal.h"

int	is_redir(t_token *tok)
{
	if (tok->type == REDIR_IN
		|| tok->type == REDIR_OUT
		|| tok->type == APPEND
		|| tok->type == HERE_DOC)
		return (TRUE);
	return (FALSE);
}

int	is_pipe(t_token *tok)
{
	if (tok->type == PIPE)
		return (TRUE);
	return (FALSE);
}

int	is_word(t_token *tok)
{
	if (tok->type == WORD)
		return (TRUE);
	return (FALSE);
}
