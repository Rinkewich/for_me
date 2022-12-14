/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shlvl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:00:34 by fardath           #+#    #+#             */
/*   Updated: 2022/11/06 21:06:09 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**init_env_lvl(char **env)
{
	int		i;
	int		shlvlint;
	char	**tmp;
	char	*shlvl;

	tmp = ft_arrnew(ft_arrlen(env));
	i = -1;
	while (env[++i])
		tmp[i] = ft_strdup(env[i]);
	shlvl = env_find_val("SHLVL", tmp);
	shlvlint = ft_atoi(shlvl) + 1;
	free(shlvl);
	shlvl = ft_itoa(shlvlint);
	tmp = export_var(ft_strjoin("SHLVL=", shlvl), tmp);
	free(shlvl);
	return (tmp);
}
