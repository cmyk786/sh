/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_safe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 20:39:36 by joloo             #+#    #+#             */
/*   Updated: 2026/02/17 00:18:04 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// gnl but no leaks
// buffer size always is 1
char	*gnl_safe(int fd)
{
	char	*res;
	char	buf[2];
	int		rc;

	res = ft_calloc(1, sizeof(char));
	if (res == NULL)
		return (NULL);
	buf[1] = '\0';
	while (1)
	{
		rc = read(fd, buf, 1);
		if (rc == -1 || (rc == 0 && res[0] == '\0'))
			return (free(res), NULL);
		if (rc == 0)
			break ;
		res = ft_strjoin_free(res, buf);
		if (res == NULL)
			return (NULL);
		if (buf[0] == '\n')
			break ;
	}
	return (res);
}

// int main(void)
// {
// 	// int	fd;
// 	char *line;
// 	// int fd = open("test.txt", O_RDONLY);
// 	line = gnl_safe(0);
// 	while (line != NULL)
// 	{
// 		printf("%s", line);
// 		free (line);
// 		line = gnl_safe(0);
// 	}
// 	return (0);
// }