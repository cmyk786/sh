/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_tok_detect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:22:17 by joloo             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/01/22 22:53:52 by joloo            ###   ########.fr       */
=======
/*   Updated: 2026/02/02 13:32:59 by joloo            ###   ########.fr       */
>>>>>>> origin/AST
/*                                                                            */
/* ************************************************************************** */

#include "exp_internal.h"

// doesn't modify in_squote && in_dquote
// returns TRUE if quoted state should be modified
static int	detect_quotes(char c, int *in_squote, int *in_dquote)
{
	if (c == '\'' && *in_dquote == 0)
		return (TRUE);
	if (c == '\"' && *in_squote == 0)
		return (TRUE);
	return (FALSE);
}

<<<<<<< HEAD
int	detect_type(t_exp_tok *tok, char *str, int i)
=======
int	exp_detect_type(t_exp_tok *tok, char *str, int i)
>>>>>>> origin/AST
{
	if (str[i] == '$' && tok->in_dquote == 1)
		return (DQUOTE_VAR);
	if (str[i] == '$' && tok->in_dquote == 0 && tok->in_squote == 0)
		return (UNQUOTE_VAR);
	if (detect_quotes(str[i], &tok->in_squote, &tok->in_dquote) == TRUE)
		return (QUOTES);
	return (WORD);
}
