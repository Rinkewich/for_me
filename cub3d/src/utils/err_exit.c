/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleaf <bleaf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:38:20 by ameteori          #+#    #+#             */
/*   Updated: 2022/11/06 23:35:04 by bleaf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	err_map(int err_code)
{
	ft_putendl_fd("\t\tError", 1);
	ft_putstr_fd("\t\t\t\tInvalid map", 1);
	if (err_code == 9)
		ft_putendl_fd("\t\t\t\tMap not closed", 1);
	if (err_code == 10)
		ft_putendl_fd("\t\t\t\tInvalid symbols in map", 1);
	if (err_code == 11)
		ft_putendl_fd("\t\t\t\tInvalid number of players", 1);
}

static void	err_ident(int err_code)
{
	ft_putstr_fd("\t\t\t\tInvalid identification:", 1);
	if (err_code == 3)
		ft_putendl_fd("\tInvalid number of identifiers", 1);
	if (err_code == 4)
		ft_putendl_fd("\tNo map", 1);
	if (err_code == 5)
		ft_putendl_fd("\t\t\t\t\t\t\tInvalid identifier", 1);
	if (err_code == 6)
		ft_putendl_fd("\tInvalid resolution", 1);
	if (err_code == 7)
		ft_putendl_fd("\tInvalid texture or no texture file", 1);
	if (err_code == 8)
		ft_putendl_fd("\tInvalid color", 1);
}

void	err_exit(int err_code)
{
	if (err_code > 8 && err_code < 12)
		err_map(err_code);
	ft_putendl_fd("\t\t\tError", 1);
	if (err_code == 0)
		ft_putendl_fd("\t\t\t\t\t\t\tInvalid input", 1);
	if (err_code == 1)
		ft_putendl_fd("\t\t\t\t\t\tNo file", 1);
	if (err_code == 2)
		ft_putendl_fd("\t\t\t\t\t\tCouldn't allocate memory", 1);
	if (err_code > 2 && err_code < 9)
		err_ident(err_code);
	exit(0);
}
