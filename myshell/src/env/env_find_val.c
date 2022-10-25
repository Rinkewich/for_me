/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_find_val.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:05:22 by fardath           #+#    #+#             */
/*   Updated: 2022/10/25 19:34:57 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
int env_place(char *val, char **envc)
{
	int	i;
	int vallen;

	i = -1;
	vallen = ft_strlen(val);
	while (envc[++i])
	{
		if (ft_strlen(envc[i]) > vallen
			&& envc[i][vallen] == '='
			&& ft_strncmp(envc[i], val, vallen) == 0)
			break ;
	}
	return (i);
}
char *env_find_val(char *val, char **envc)
{
	int	i;
	char	*result;

	if (ft_strlen(val) == 1 && val[0] == '?')
	{
		result = ft_itoa(g_sigint);
		return(result);
	}
	i = env_place(val, envc);
	if (!envc[i])
		return (NULL);
	result = ft_strdup(envc[i] + ft_strlen(val) + 1);
	return(result);
}