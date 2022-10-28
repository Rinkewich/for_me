/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:38:43 by fardath           #+#    #+#             */
/*   Updated: 2022/10/28 19:23:01 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "spliter.h"

t_split_data	*init_split_data(char *line)
{
	t_split_data	*data;
	
	data = malloc(sizeof(t_split_data));
	data->index = 0;
	data->line = line;
	data->words = ft_arrnew(0);
	return (data);
}

void spliter(t_plit *split)
{
	t_split_data	*data;

	data = init_split_data(split->line);
	while (check_letter(data))
	{
		if (check_separator(data))
			;
	}
	free(data);
}