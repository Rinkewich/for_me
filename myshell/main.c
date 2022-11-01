/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:26:58 by fardath           #+#    #+#             */
/*   Updated: 2022/11/01 17:53:04 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env.h"

int		g_sigint;
void	master(t_plit *split)
{
	while (1)
	{
		split->line = readline(MINISHELL);
		if (!split->line)
		{
			g_sigint = 128 - 1;
			if (write(2, "\n", 1) < 0)
				perror("\n");
			exit(g_sigint);
		}
		if (ft_strlen(split->line) == 0 && split->line[0] == 0)
			;
		else
		{
			add_history(split->line);
			what_env(split, 0, 0, 0);
			spliter(split);
			parser(split);
		}
	}
}
int	main(int argc, char **argv, char **envp)
{
	t_plit *split;

	g_sigint = 0;
	split = init_plit(argc, argv, envp);
	master(split);
	return (0);
}
