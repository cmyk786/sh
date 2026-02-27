/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:17:43 by joloo             #+#    #+#             */
/*   Updated: 2026/02/27 15:16:30 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXP_H
# define EXP_H

int		expand(char ***argv, t_env *env);
int		expand_redir(char **str, t_env *env);
int		exp_hd(t_redir *node, t_env *env);

#endif