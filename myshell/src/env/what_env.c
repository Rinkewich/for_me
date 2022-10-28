/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:12:09 by fardath           #+#    #+#             */
/*   Updated: 2022/10/28 18:25:15 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_envvar(char **env, char *result, char *line, int len)
{
	int		i;
	char	*tmp;
	char	*envvar_name;
	char	*envvar_val;

	envvar_name = ft_strnew(len);
	i = -1;
	while (++i < len)
		envvar_name[i] = line[i];
	envvar_val = env_find_val(envvar_name, env);
	free(envvar_name);
	if (envvar_val)
	{
		tmp = result;
		result = ft_strjoin(result, envvar_val);
		free(envvar_val);
		free(tmp);
	}
	return (result);
}

int	shift_to_separator(char *str)
{
	int	j;

	j = -1;
	while (str[++j]
		&& !ft_strchr(SEPARATORS, str[j]))
		;
	return (j);
}

void	what_env(t_plit *split, int sq, int dq, int i)
{
	int			j;
	char		*result;

	result = ft_strnew(0);
	while (split->line[i])
	{
		while (split->line[i] && (split->line[i] != '$' || sq))
		{
			if (!dq && split->line[i] == '\'')
				sq = 1 - sq;
			if (!sq && split->line[i] == '\"')
				dq = 1 - dq;
			result = ft_str_addletter(result, split->line[i]);
			i++;
		}
		if (split->line[i] == '$')
		{
			j = shift_to_separator(split->line + ++i);
			result = join_envvar(split->env, result, split->line + i, j);
			i = i + j;
		}
	}
	split->line = result;
}
