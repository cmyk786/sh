#include "ex.h"

int	is_n(char *arg)
{
    int	i;

	i = 1;
    if (arg[0] != '-' || arg[1] != 'n')
        return (0);
    while (arg[i])
    {
        if (arg[i] != 'n')
            return (0);
        i++;
    }
    return (1);
}

int	echo(char **args)
{
    int	i;
    int	n;

	i = 1;
	n = 1;
    while (args[i] && is_n(args[i]))
    {
        n = 0;
        i++;
    }
    while (args[i])
    {
        ft_putstr_fd(args[i], STDOUT_FILENO);
        if (args[i + 1])
            ft_putchar_fd(' ', STDOUT_FILENO);
        i++;
    }
    if (n)
        ft_putchar_fd('\n', STDOUT_FILENO);
    return (0);

}
