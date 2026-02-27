/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 13:05:01 by joloo             #+#    #+#             */
/*   Updated: 2026/02/27 13:51:56 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// adds a str to the end of the arr
char	**ft_strarrjoin(char **arr, char *str)
{
	char	**res;
	int		len;
	int		i;

	len = ft_strarr_len(arr);
	res = malloc(sizeof(char *) * (len + 1 + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (arr[i] != NULL)
	{
		res[i] = ft_strdup(arr[i]);
		if (res[i] == NULL)
			return (ft_free_str_arr(res), NULL);
		i++;
	}
	res[i] = str;
	res[i + 1] = NULL;
	return (res);
}

// int	main(void)
// {
// 	char **arr = ft_calloc(sizeof(char *), 1);
// 	char *str = "aa";

// 	char **res = ft_strarrjoin(arr, str);
// 	printf("%s\n", res[0]);
// 	printf("%p\n", res[1]);
// 	ft_free_str_arr(res);
// }