/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:34:46 by joloo             #+#    #+#             */
/*   Updated: 2026/01/30 22:16:34 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_itoa_array(int *arr, int size)
{
	char	**res;
	int		i;

	i = 0;
	res = malloc(sizeof(char *) * (size + 1));
	if (res == NULL)
		return (0);
	while (i < size)
	{
		res[i] = ft_itoa(arr[i]);
		if (res[i] == NULL)
		{
			ft_free_str_arr(res);
			return (NULL);
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}
