/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 00:57:24 by fardath           #+#    #+#             */
/*   Updated: 2022/11/06 18:09:03 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "executor.h"


char	**change_pwds(char *target, char **env)
{
	char	*tmp;
	char	*new_val;
	char	pwd[10000];

	env = unset_var(target, env);
	if (!getcwd(pwd, sizeof(pwd)))
		perror(pwd);
	tmp = ft_strjoin(target, "=");
	new_val = ft_strjoin(tmp, pwd);
	free(tmp);
	env = export_var(new_val, env);
	return (env);
}

char	**real_cd(char *target, char **env)
{
	env = change_pwds("OLDPWD", env);
	if (chdir(target) == -1)
	{
		perror(target);
		free(target);
		g_sigint = 1;
		return (env);
	}
	env = change_pwds("PWD", env);
	free(target);
	g_sigint = 0;
	return (env);
}

char	**cd_to_many_arguments(char **env)
{
	print_errormsg("cd: too many arguments\n");
	g_sigint = 1;
	return (env);
}

char	**cd_no_arguments(char **env)
{
	char	*target;

	target = env_find_val("HOME", env);
	if (target == NULL)
	{
		print_errormsg("cd: HOME not set\n");
		return (env);
	}
	return (real_cd(target, env));
}

char	**cd_back(char **env)
{
	char	*target;

	target = env_find_val("OLDPWD", env);
	if (target == NULL)
	{
		print_errormsg("cd: OLDPWD not set\n");
		return (env);
	}
	printf("%s\n", target);
	return (real_cd(target, env));
}
