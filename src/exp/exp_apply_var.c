/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_apply_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:25:44 by joloo             #+#    #+#             */
/*   Updated: 2026/01/30 00:54:26 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp_internal.h"

t_token	*exp_apply_dquote_var(char *exp_value)
{
	t_token	*res;

	res = create_node(exp_value, ft_strlen(exp_value), WORD);
	return (res);
}

// value = "" will be added, filter later
t_token	*exp_apply_unquote_var(char *exp_value)
{
	t_token	*res;
	int		i;

	res = NULL;
	i = 0;
	if (exp_value[0] == '\0')
	{
		if (exp_apply_unquote_add_word(&res, exp_value, &i) == FAILURE)
			return (free(exp_value), free_tokens(&res), NULL);
	}
	else
	{
		if (exp_apply_unquote_var_loop(&res, exp_value) == FAILURE)
			return (NULL);
	}
	return (free(exp_value), res);
}

int	exp_apply_unquote_var_loop(t_token **res, char *exp_value)
{
	int	i;

	i = 0;
	while (exp_value[i] != '\0')
	{
		if (ft_isspace(exp_value[i]) == TRUE)
		{
			if (add_delimiter(res) == FAILURE)
				return (free(exp_value), free_tokens(res), FAILURE);
			while (ft_isspace(exp_value[i]) == TRUE)
				i++;
		}
		else
		{
			if (exp_apply_unquote_add_word(res, exp_value, &i) == FAILURE)
				return (free(exp_value), free_tokens(res), FAILURE);
		}
	}
	return (SUCCESS);
}

int	exp_apply_unquote_add_word(t_token **res, char *str, int *i)
{
	int		j;
	t_token	*node;

	j = 0;
	while (str[*i + j] != '\0'
		&& ft_isspace(str[*i + j]) != TRUE)
	{
		j++;
	}
	node = create_node(str + *i, j, WORD);
	if (node == NULL)
		return (FAILURE);
	tokenadd_back(res, node);
	*i += j;
	return (SUCCESS);
}
