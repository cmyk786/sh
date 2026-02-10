static char	*get_cd_path(char **arg, t_env **env)
{
	char	*path;

	if (!arg[1] || ft_strcmp(arg[1], "~") == 0)
	{
		path = get_env_value(*env, "HOME");
		if (!path)
			ft_message("cd: HOME not set\n");
	}
	else if (ft_strcmp(arg[1], "-") == 0)
	{
		path = get_env_value(*env, "OLDPWD");
		if (!path)
			ft_message("cd: OLDPWD not set\n");
		else
			printf("%s\n", path);
	}
	else
		path = arg[1];
	return (path);
}

static int	update_pwd(t_env **env, char *oldpwd)
{
	char	*pwd;

	if (set_env_value("OLDPWD", oldpwd, env))
	{
		perror("cd: failed to update OLDPWD");
		return (1);
	}
	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (1);
	if (set_env_value("PWD", pwd, env))
	{
		perror("cd: failed to update PWD");
		free(pwd);
		return (1);
	}
	free(pwd);
	return (0);
}

static int	change_dir(char *path, t_env **env)
{
	char	*oldpwd;

	oldpwd = getcwd(NULL, 0);
	if (!oldpwd)
		return (1);
	if (chdir(path) != 0)
	{
		perror("cd");
		free(oldpwd);
		return (1);
	}
	if (update_pwd(env, oldpwd))
	{
		free(oldpwd);
		return (1);
	}
	free(oldpwd);
	return (0);
}

int	cd(char **arg, t_env **env)
{
	char	*path;

	if (arg[1] && arg[2])
		return (ft_message("cd: too many arguments\n"), 1);
	path = get_cd_path(arg, env);
	if (!path)
		return (1);
	return (change_dir(path, env));
}