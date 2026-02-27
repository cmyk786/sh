/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrjoin_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 13:01:46 by joloo             #+#    #+#             */
/*   Updated: 2026/02/27 13:38:39 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_strarrjoin but frees arr
char	**ft_strarrjoin_free(char **arr, char *str)
{
	char	**res;

	res = ft_strarrjoin(arr, str);
	return (ft_free_str_arr(arr), res);
}
