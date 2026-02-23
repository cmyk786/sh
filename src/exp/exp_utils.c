/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:10:52 by joloo             #+#    #+#             */
/*   Updated: 2026/02/23 19:49:33 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp_internal.h"

// name (bash)
// A word consisting solely of letters, numbers, and 
// underscores and beginning with a letter or underscore.
// returns the len of a valid name
int	name_len(char *str)
{
	int	i;

	if (str[0] == '\0')
		return (0);
	if (str[0] == '?')
		return (1);
	if (ft_isalpha(str[0]) != 1 && str[0] != '_')
		return (0);
	i = 1;
	while (str[i] != '\0'
		&& (ft_isalpha(str[i]) == 1
			|| ft_isdigit(str[i]) == 1
			|| str[i] == '_'))
	{
		i++;
	}
	return (i);
}
