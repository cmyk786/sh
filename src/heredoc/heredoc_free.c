/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:30:47 by joloo             #+#    #+#             */
/*   Updated: 2026/01/30 19:37:35 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc_internal.h"

void	hd_free(t_hd *data)
{
	free(data->delimiter);
	free(data->buffer);
	if (data->written != TRUE && data->pipe[0] != -1)
	{
		close(data->pipe[0]);
		data->pipe[0] = -1;
	}
	if (data->pipe[1] != -1)
	{
		close(data->pipe[1]);
		data->pipe[1] = -1;
	}
}
