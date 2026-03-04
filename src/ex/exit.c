/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 02:34:01 by joloo             #+#    #+#             */
/*   Updated: 2026/03/01 02:34:03 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

static int	is_num(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	exit_clean(t_ast *node, t_env **env, int n)
{
	if (node)
		free_ast(&node);
	if (env)
		env_free_all(env);
	rl_clear_history();
	exit(n);
}

void	ft_exit(char **a, t_ast *node, t_env **env)
{
	int	n;

	if (!a[1])
	{
		printf("exit\n");
		exit_clean(node, env, g_s);
	}
	if (!is_num(a[1]))
	{
		printf("exit\n");
		ft_message("exit: ");
		ft_message(a[1]);
		ft_message(": numeric argument required\n");
		exit_clean(node, env, 2);
	}
	if (a[2])
	{
		printf("exit\n");
		ft_message("exit: too many arguments\n");
		g_s = 2;
		return ;
	}
	n = ft_atoi(a[1]);
	printf("exit\n");
	exit_clean(node, env, (unsigned char)n);
}

