/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:03:49 by fardath           #+#    #+#             */
/*   Updated: 2022/11/06 20:50:27 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*mini_env(t_plit *mini)
{
	char	*result;
	char	*tmp;
	int		i;

	i = -1;
	result = malloc(sizeof(char) * 1);
	result[0] = 0;
	while (mini->env[++i])
	{
		tmp = result;
		result = ft_strjoin(result, mini->env[i]);
		free(tmp);
		tmp = result;
		result = ft_strjoin(result, "\n");
		free(tmp);
	}
	printf("%s", result);
	return (result);
}
