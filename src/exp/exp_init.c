/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:50:11 by joloo             #+#    #+#             */
/*   Updated: 2026/01/22 22:44:41 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp_internal.h"

int	exp_init(t_exp *exp, char **argv, t_env *env)
{
	ft_memset(exp, 0, sizeof(t_exp));
	exp->tok.argv = argv;
	exp->env = env;
	return (SUCCESS);
}
