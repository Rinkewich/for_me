#include "minishell.h"
#include "hed.h"

int		g_sigint;

int	main(int argc, char **argv, char **envp)
{
	t_plit *split;

	g_sigint = 0;
	split = init_plit(argc, argv, envp);
	return (0);
}
