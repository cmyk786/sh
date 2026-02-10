#include "ex.h"

static int	env_list_size(t_env *env)
{
    int	count;

	count = 0;
    while (env)
    {
        count++;
        env = env->next;
    }
    return (count);
}

char	**env_to_enva(t_env *env)
{
	char	**enva;
	int		i;
	t_env	*tmp;
	char	*tmp_str;

	i = 0;
	tmp = env;
	enva = malloc(sizeof(char *) * (env_list_size(env) + 1));
	if (!enva)
		return (NULL);
	while (tmp)
	{
		tmp_str = ft_strjoin(tmp->key, "=");
		if (!tmp_str)
			return (ft_free_str_arr(enva), NULL);
		enva[i] = ft_strjoin(tmp_str, tmp->val);
		free(tmp_str);
		if (!enva[i])
			return (ft_free_str_arr(enva), NULL);
		i++;
		tmp = tmp->next;
	}
	enva[i] = NULL;
	return (enva);

}
