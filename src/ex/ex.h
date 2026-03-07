/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 02:33:54 by joloo             #+#    #+#             */
/*   Updated: 2026/03/01 02:33:56 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX_H
# define EX_H

# include <sys/wait.h>
# include <sys/stat.h>
# include "libft.h"
# include "parsing.h"
# include "../../src/env/env_internal.h"
# include "exp.h"

void	set_sig_child(void);
void	set_sig_h(void);
void	set_sig(void);
int		wait_child(pid_t pid);
int		is_redir(t_token_type type);
int		apply_redir(t_ast *node, t_env *e);
void	ft_message(char *s);
char	**env_to_enva(t_env *env);
int		is_builtin(char *cmd);
int		ex_builtin(t_ast *node, t_env **env);
int		ex(t_ast *node, t_env **env);
int		ex_pipe(t_ast *node, t_env **env);
int		ex_cmd(t_ast *node, t_env **env, int in_fd, int out_fd);
int		ex_cmd_child(t_ast *node, t_env **env, char *s);
int		cd(char **argv, t_env **env);
int		expn(t_ast *node, t_env *env, int in_fd, int out_fd);
int		echo(char **a);
int		ft_pwd(void);
int		unset(char **a, t_env **env);
int		ft_env(t_env *env);
int		ft_export(char **arg, t_env **env);
void	ft_exit(char **a, t_ast *node, t_env **env);
void	set_fd(int in_fd, int out_fd);
int		env_size(t_env *env);
t_env	*copy_env_node(t_env *env);
t_env	*copy_env(t_env *env);
void	sort_env(t_env *env);
void	print_export_error(char *s);
void	print_export(t_env *env);
int		check_valid(char *s);
int		add_env_node(char *key, char *value, t_env **env);
t_env	*check_key(char *key, t_env *env);
int		set_env_value(char *key, char *value, t_env **env);
int		export_var(char *s, t_env **env);

#endif
