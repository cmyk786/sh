#include "ex.h"

static t_env	*create_env_node(char *key, char *value)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	node->key = ft_strdup(key);
	if (!node->key)
	{
		free(node);
		return (NULL);
	}
	if (value)
	{
		node->value = ft_strdup(value);
		if (!node->value)
		{
			free(node->key);
			free(node);
			return (NULL);
		}
	}
	else
		node->value = NULL;
	node->next = NULL;
	return (node);
}

int	add_env_node(char *key, char *value, t_env **env)
{
	t_env	*node;
	t_env	*tmp;

	node = create_env_node(key, value);
	if (!node)
		return (1);
	if (!*env)
	{
		*env = node;
		return (0);
	}
	tmp = *env;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return (0);
}

void	print_export_error(char *s)
{
	ft_message("export:'");
	ft_message(s);
	ft_message("': not a valid identifier\n");
}

void	print_export(t_env *env)
{
	t_env	*copy;
	t_env	*list;

	copy = copy_env(env);
	if (!copy)
		return ;
	sort_env(copy);
	list = copy;
	while (copy)
	{
		if (copy->value)
			printf("declare -x %s=\"%s\"\n", copy->key, copy->value);
		else
			printf("declare -x %s\n", copy->key);
		copy = copy->next;
	}
	env_free_all(&list);
}

int	check_valid(char *s)
{
	if (!s)
		return (1);
	if (!ft_isalpha(*s) && (*s != '_'))
		return (1);
	s++;
	while (*s)
	{
		if (!ft_isalnum(*s) && (*s != '_'))
			return (1);
		s++;
	}
	return (0);

}



