/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:17:43 by joloo             #+#    #+#             */
/*   Updated: 2026/02/20 22:46:12 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXP_H
# define EXP_H

char	**exp(char **argv, t_env *env);
int		expand_redir(char ***res, char *str, t_env *env);
int		exp_hd(t_redir *node,t_env *env);

#endif