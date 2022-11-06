/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errormsg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:08:07 by fardath           #+#    #+#             */
/*   Updated: 2022/11/06 20:50:44 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_errormsg(char *errormsg)
{
	if (write(STDERR_FILENO, errormsg, ft_strlen(errormsg)) < 0)
		perror("write");
}
