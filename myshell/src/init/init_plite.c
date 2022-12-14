/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:35:25 by fardath           #+#    #+#             */
/*   Updated: 2022/11/06 20:52:28 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_plit	*init_plit(int argc, char **argv, char **env)
{
	t_plit	*split;

	split = malloc(sizeof(t_plit));
	split->pid = getpid();
	split->argv = argv;
	split->argc = argc;
	split->temporary = 0;
	split->env = init_env_lvl(env);
	return (split);
}
