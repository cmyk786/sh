/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 02:34:54 by joloo             #+#    #+#             */
/*   Updated: 2026/03/01 02:34:55 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

void	set_sig_child(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

static void	sig_prompt(int sig)
{
	(void)sig;
	g_s = 130;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	set_sig(void)
{
	signal(SIGINT, sig_prompt);
	signal(SIGQUIT, SIG_IGN);
}

static void	sig_handle(int sig)
{
	(void)sig;
	write(2, "\n", 1);
	g_s = 130;
}

void	set_sig_h(void)
{
	signal(SIGINT, sig_handle);
}
