/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_letter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:01:50 by fardath           #+#    #+#             */
/*   Updated: 2022/11/06 20:52:01 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	check_letter(t_split_data *data)
{
	return (data->line[data->index]);
}
