/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_internal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:03:23 by joloo             #+#    #+#             */
/*   Updated: 2026/01/15 13:00:58 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_INTERNAL_H
# define ENV_INTERNAL_H

# include "env.h"
# include "libft.h"

# ifndef SUCCESS
#  define SUCCESS 1
# endif

# ifndef FAILURE
#  define FAILURE 0
# endif

// first node must be key=? for the lifespan of env
typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

t_env	*find_node(t_env *env, char *key);
t_env	*env_node_new(char *key, char *value);
void	env_add_back(t_env **head, t_env *new);

#endif