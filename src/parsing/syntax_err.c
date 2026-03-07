/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 23:11:37 by joloo             #+#    #+#             */
/*   Updated: 2026/03/07 21:33:51 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_internal.h"

void	syntax_err(t_token *tok)
{
	if (tok == NULL)
	{
		ft_putstr_fd("error newlwine\n", 2);
	}
	else
	{
		ft_putstr_fd("syntax error near unexpected token '", 2);
		ft_putstr_fd(tok->value, 2);
		ft_putstr_fd("'\n", 2);
	}
}
