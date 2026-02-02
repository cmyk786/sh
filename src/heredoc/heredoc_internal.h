/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:30:57 by joloo             #+#    #+#             */
/*   Updated: 2026/02/02 14:27:47 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_INTERNAL_H
# define HEREDOC_INTERNAL_H

# include "../../includes/heredoc.h"
# include "libft.h"

# ifndef SUCCESS
#  define SUCCESS 1
# endif

# ifndef FAILURE
#  define FAILURE 0
# endif

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

typedef struct s_hd
{
	char	*delimiter;
	int		is_quoted;
	char	*buffer;
	int		pipe[2];
	int		written;
	t_env	*env;
}	t_hd;

char *exp_hd(char *buffer, t_env *env);
int	exp_hd_add_word(char *buffer, char **res, int *i);
int	exp_hd_add_var(char *buffer, char **res, int *i, t_env *env);

void	hd_free(t_hd *data);

int	read_stdin(t_hd *data);
void	print_prompt(void);
int	check_delimiter(char *line, char *delimiter);
int	free_gnl(int fd);

int	check_quotes(t_hd *data, char *delimiter);
int	hd_expand(t_hd *data);
int	write_to_pipe(t_hd *data);

#endif