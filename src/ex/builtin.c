/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwei <yiwei@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 02:32:45 by yiwei             #+#    #+#             */
/*   Updated: 2026/03/01 02:32:47 by yiwei            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (!ft_strcmp(cmd, "cd") || !ft_strcmp(cmd, "echo")
		|| !ft_strcmp(cmd, "pwd") || !ft_strcmp(cmd, "export")
		|| !ft_strcmp(cmd, "unset") || !ft_strcmp(cmd, "env")
		|| !ft_strcmp(cmd, "exit"))
		return (1);
	return (0);
}

int	ex_builtin(t_ast *node, t_env **env)
{
	char	**argv;

	argv = node->simple_cmd.argv;
	if (!node || !argv || !argv[0])
		return (1);
	if (!ft_strcmp(argv[0], "cd"))
		return (cd(argv, env));
	if (!ft_strcmp(argv[0], "echo"))
		return (echo(argv));
	if (!ft_strcmp(argv[0], "pwd"))
		return (ft_pwd());
	if (!ft_strcmp(argv[0], "export"))
		return (ft_export(argv, env));
	if (!ft_strcmp(argv[0], "unset"))
		return (unset(argv, env));
	if (!ft_strcmp(argv[0], "env"))
		return (ft_env(*env));
	if (!ft_strcmp(argv[0], "exit"))
		ft_exit(argv, node, *env);
	return (1);
}
