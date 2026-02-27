/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:38:18 by joloo             #+#    #+#             */
/*   Updated: 2026/02/27 15:15:32 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_internal.h"

int	parse_ast(t_token *tok, t_ast **root)
{
	t_token	*temp;

	temp = tok;
	*root = ast_new(&temp);
	if (*root == NULL)
		return (FAILURE);
	return (SUCCESS);
}
