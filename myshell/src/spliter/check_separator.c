/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_separator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:16:34 by fardath           #+#    #+#             */
/*   Updated: 2022/10/28 19:21:52 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "spliter.h"

int check_separator(t_split_data *data)
{
	char	c;

	c = data->line[data->index];
	if (c == REDIRIN[0] || c == REDIROUT[0] || c == PIPE[0] || c == SPACE)
		return (1);
	return (0);
}