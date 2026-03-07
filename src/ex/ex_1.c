/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 02:33:28 by joloo             #+#    #+#             */
/*   Updated: 2026/03/01 02:33:30 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

static char	*join_cmd(char *path, char *cmd)
{
	char	*tmp;
	char	*full;

	tmp = ft_strjoin(path, "/");
	if (!tmp)
		return (NULL);
	full = ft_strjoin(tmp, cmd);
	free(tmp);
	return (full);
}

static char	*search_paths(char **paths, char *cmd)
{
	int		i;
	char	*full;

	i = 0;
	while (paths[i])
	{
		full = join_cmd(paths[i], cmd);
		if (full && access(full, F_OK) == 0)
			return (full);
		free(full);
		i++;
	}
	return (NULL);
}

static char	*find_cmd(char *cmd, t_env *env)
{
	t_env	*tmp;
	char	**paths;
	char	*full;

	if (!cmd || !*cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	tmp = env;
	while (tmp && ft_strcmp(tmp->key, "PATH"))
		tmp = tmp->next;
	if (!tmp || !tmp->value)
		return (NULL);
	paths = ft_split(tmp->value, ':');
	if (!paths)
		return (NULL);
	full = search_paths(paths, cmd);
	ft_free_str_arr(paths);
	return (full);
}

static void	ex_error(char *msg, char *cmd, int code, t_ast *node)
{
	ft_message(msg);
	ft_message(cmd);
	ft_message("\n");
	free_ast(&node);
	free(msg);
	exit(code);
}

int	ex_cmd_child(t_ast *node, t_env **env, char *s)
{
	char		*cmd_path;
	char		**child_env;
	struct stat	st;

	set_sig_child();
	cmd_path = find_cmd(node->simple_cmd.argv[0], *env);
	if (!cmd_path)
		ex_error(ft_strdup(s), ": command not found", 127, node);
	if (stat(cmd_path, &st) == -1)
		ex_error(cmd_path, ": No such file or directory", 127, node);
	if (S_ISDIR(st.st_mode))
		ex_error(cmd_path, ": Is a directory", 126, node);
	if (access(cmd_path, X_OK))
		ex_error(cmd_path, ": Permission denied", 126, node);
	child_env = env_to_enva(*env);
	if (!child_env)
	{
		perror("malloc");
		free(cmd_path);
		free_ast(&node);
		exit(1);
	}
	execve(cmd_path, node->simple_cmd.argv, child_env);
	ex_error(cmd_path, ": Exec format error", 126, node);
	return (1);
}
