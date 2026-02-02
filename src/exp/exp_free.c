/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 20:41:30 by joloo             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/02/01 15:12:35 by joloo            ###   ########.fr       */
=======
/*   Updated: 2026/02/02 13:36:58 by joloo            ###   ########.fr       */
>>>>>>> origin/AST
/*                                                                            */
/* ************************************************************************** */

#include "exp_internal.h"

void	exp_free(t_exp *exp, char ***argv)
{
	ft_free_str_arr(*argv);
	argv = NULL;
<<<<<<< HEAD
	free_tokens(&exp->tok.tokens);
}

void	free_token(t_token *node)
=======
	exp_free_tokens(&exp->tok.tokens);
}

void	exp_free_token(t_token *node)
>>>>>>> origin/AST
{
	free(node->value);
	free(node);
}
<<<<<<< HEAD
void	free_tokens(t_token **lst)
=======

void	exp_free_tokens(t_token **lst)
>>>>>>> origin/AST
{
	t_token	*temp;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
<<<<<<< HEAD
		free_token(*lst);
		*lst = temp;
	}
	*lst = NULL;
}
=======
		exp_free_token(*lst);
		*lst = temp;
	}
	*lst = NULL;
}
>>>>>>> origin/AST
