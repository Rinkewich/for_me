/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errormsg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:08:07 by fardath           #+#    #+#             */
/*   Updated: 2022/11/06 18:11:49 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	print_errormsg(char *errormsg)
{
	if (write(STDERR_FILENO, errormsg, ft_strlen(errormsg)) < 0)
		perror("write");
}
