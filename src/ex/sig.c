#include "ex.h"

void	set_sig_child(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	set_sig(void)
{
	signal(SIGINT, sig_prompt);
    signal(SIGQUIT, SIG_IGN);
}

void	sig_prompt(int sig)
{
	(void)sig;
	s = 130;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();

}

static void sig_handle(int sig)
{
	(void)sig;
	write(2, "\n", 1);
	s = 130;
}

void	set_sig_h(void)
{
	signal(SIGINT, sig_handle);
}
