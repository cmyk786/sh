int	ft_env(t_env *env)
{
	while (env)
	{
		if (env->val)
			printf("%s=%s\n", env->key, env->val);
		env = env->next;
	}
	return (0);
}