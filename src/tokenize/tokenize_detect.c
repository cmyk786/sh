/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_detect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:06:33 by joloo             #+#    #+#             */
/*   Updated: 2026/01/02 20:06:36 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize_internal.h"

void	detect_quotes(char c, int *in_squote, int *in_dquote)
{
	if (c == '\'' && *in_dquote == 0)
	{
		if (*in_squote == 0)
			*in_squote = 1;
		else
			*in_squote = 0;
	}
	if (c == '\"' && *in_squote == 0)
	{
		if (*in_dquote == 0)
			*in_dquote = 1;
		else
			*in_dquote = 0;
	}
}

int	detect_type(t_tok *data, int i)
{
	int	type;

	type = 0;
	while (data->token_lookup[type] != NULL)
	{
		if (ft_strncmp(data->input + i, data->token_lookup[type],
				ft_strlen(data->token_lookup[type])) == 0)
			return (type);
		type++;
	}
	return (type);
}
