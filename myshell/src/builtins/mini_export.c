/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:03:55 by fardath           #+#    #+#             */
/*   Updated: 2022/11/06 21:00:42 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**add_var(char **env, char *arg)
{
	int		i;
	char	**new_env;

	new_env = ft_arrnew(ft_arrlen(env) + 1);
	i = -1;
	while (env[++i])
		new_env[i] = ft_strdup(env[i]);
	new_env[i] = ft_strdup(arg);
	free_env(env);
	return (new_env);
}

char	*ft_strcpy_len(char *src, int len)
{
	int		i;
	char	*str;

	str = ft_strnew(len);
	i = -1;
	while (++i < len)
		str[i] = src[i];
	return (str);
}

char	**export_var(char *arg, char **env)
{
	char	*equalschar;
	char	*envvar;

	equalschar = ft_strchr(arg, '=');
	if (!equalschar)
		return (env);
	envvar = ft_strcpy_len(arg, equalschar - arg);
	env = unset_var(envvar, env);
	free(envvar);
	env = add_var(env, arg);
	return (env);
}

char	**mini_export(char **argv, char **env, t_plit *mini)
{
	int		i;

	i = 0;
	if (!argv[1])
		mini_env(mini);
	while (argv[++i])
		env = export_var(argv[i], env);
	g_sigint = 0;
	return (env);
}
