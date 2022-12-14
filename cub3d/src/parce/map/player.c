/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpirzad <bpirzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:30:57 by ameteori          #+#    #+#             */
/*   Updated: 2022/11/06 23:38:40 by bpirzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static void	set_camera(t_cub *cub, double dir_x, double plane_x, double plane_y)
{
	cub->plr->dir_x = dir_x;
	cub->plr->plane_x = plane_x;
	cub->plr->plane_y = plane_y;
}

static void	set_pos(int x, int y, t_cub *cub)
{
	cub->plr->pos_x = x;
	cub->plr->pos_y = y;
}

void	set_dir(char dir, int x, int y, t_cub *cub)
{
	if (dir == 'E')
	{
		cub->plr->dir_y = 0.0;
		set_camera(cub, 1.0, 0.0, 0.66);
	}
	else if (dir == 'W')
	{
		cub->plr->dir_y = 0.0;
		set_camera(cub, -1.0, 0.0, -0.66);
	}
	else if (dir == 'N')
	{
		cub->plr->dir_y = -1.0;
		set_camera(cub, 0.0, 0.66, 0.0);
	}
	else if (dir == 'S')
	{
		cub->plr->dir_y = 1.0;
		set_camera(cub, 0.0, -0.66, 0.0);
	}
	set_pos(x, y, cub);
}
