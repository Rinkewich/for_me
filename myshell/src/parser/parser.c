/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:26:01 by fardath           #+#    #+#             */
/*   Updated: 2022/10/31 20:08:56 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void parser(t_plit *split)
{
	t_parser	*data;

	data = init_parser(split->split_line);
	while (check_word(data))
	{
		if (find_redirect(data))
			put_redirect(split, data);
	}
}