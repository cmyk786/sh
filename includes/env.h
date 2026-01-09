/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:02:33 by joloo             #+#    #+#             */
/*   Updated: 2026/01/09 18:18:03 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

typedef struct s_env	t_env;

char	*env_get(t_env *env, char *key);
int		env_set(t_env *env, char *key, char *value);
void	env_unset(t_env *env, char *key);

int		env_set_exit_status(t_env **head, int status);

char	*extract_key(char *str);
char	*extract_value(char *str);

void	env_free_node(t_env *node);
void	env_free_all(t_env **head);

t_env	*env_init(char **envp);

void	env_print(t_env *head);

#endif