t_env	*check_key(char *key, t_env *env)
{
	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
			return (env);
		env = env->next;
	}
	return (NULL);
}

int	set_env_value(char *key, char *value, t_env **env)
{
	t_env	*node;

	node = check_key(key, *env);
	if (node)
	{
		if (value)
		{
			free(node->val);
			node->val = ft_strdup(value);
			if (!node->val)
				return (1);
		}
	}
	else
	{
		if (add_env_node(key, value, env))
			return (1);
	}
	return (0);
}

static int	export_set_env(char *key, char *val, t_env **env)
{
	if (check_valid(key))
	{
		print_export_error(key);
		free(key);
		free(val);
		return (1);
	}
	if (set_env_value(key, val, env))
	{
		free(key);
		free(val);
		ft_message("Malloc fail\n");
		return (1);
	}
	free(key);
	free(val);
	return (0);
}

int	export_var(char *s, t_env **env)
{
	char	*key;
	char	*val;
	char	*pos;

	pos = ft_strchr(s, '=');
	if (pos)
	{
		key = ft_substr(s, 0, pos - s);
		val = ft_strdup(pos + 1);
	}
	else
	{
		key = ft_strdup(s);
		val = NULL;
	}
	return (export_set_env(key, val, env));
}

int	export(char **arg, t_env **env)
{
	int	i;
	int	code;

	i = 1;
	code = 0;
	if (!arg[1])
	{
		print_export(*env);
		return (0);
	}
	while (arg[i])
	{
		if (export_var(arg[i], env))
			code = 1;
		i++;
	}
	return (code);
}