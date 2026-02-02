/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 23:11:37 by joloo             #+#    #+#             */
/*   Updated: 2026/02/02 14:43:11 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_internal.h"

void	syntax_err(t_token *tok)
{
	if (tok == NULL)
		printf("error newlwine\n");
	else
		printf("syntax error near unexpected token '%s'\n", tok->value);
}
