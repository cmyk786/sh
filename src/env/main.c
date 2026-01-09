/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:08:21 by joloo             #+#    #+#             */
/*   Updated: 2026/01/09 18:47:47 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <stdio.h>
#include "libft.h"

// int	main(int argc, char **argv, char **envp)
// {
// 	(void) argc;
// 	(void) argv;

// 	t_env *env = env_init(envp);
// 	env_set_exit_status(&env, 69);
// 	printf("%s\n", env_get(env, "?"));
// 	printf("%s\n", env_get(env, "HOME"));
// 	printf("%s\n", env_get(env, "erm"));
// 	env_set(env, ft_strdup("erm"),  ft_strdup("AAA"));
// 	printf("%s\n", env_get(env, "erm"));
// 	env_free_all(&env);
// }