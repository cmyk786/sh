/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_internal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:18:25 by joloo             #+#    #+#             */
/*   Updated: 2026/01/14 10:23:06 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXP_INTERNAL_H
# define EXP_INTERNAL_H

# include "libft.h"
# include "exp.h"

typedef enum e_exp_type
{
	DQUOTE_VAR,
	UNQUOTE_VAR,
	DELIMITER,
	QUOTES,
	WORD,
}	t_exp_type;

#endif