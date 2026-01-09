/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_extract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:10:40 by joloo             #+#    #+#             */
/*   Updated: 2026/01/09 18:36:18 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_internal.h"

char	*extract_key(char *str)
{
	return (ft_substr(str, 0, ft_strchr_pos(str, '=') - 1));
}

char	*extract_value(char *str)
{
	return (ft_substr(str,
		ft_strchr_pos(str, '='),
		ft_strlen(str + ft_strchr_pos(str, '='))));
}