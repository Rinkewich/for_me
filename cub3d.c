/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpirzad <bpirzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:41:35 by ameteori          #+#    #+#             */
/*   Updated: 2022/11/06 23:39:23 by bpirzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

static t_cub	*init_cub(void)
{
	t_cub	*cub;

	cub = ft_calloc(sizeof(t_cub), 1);
	if (!cub)
		err_exit(2);
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return (ERR);
	cub->width = 400;
	cub->height = 0;
	cub->map_x = 0;
	cub->map_y = 0;
	cub->save_bmp = 0;
	cub->sprites_num = 0;
	cub->sprite_i = 0;
	return (cub);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	cub = init_cub();
	init_texture(cub, 8);
	init_plr(cub);
	init_game_keybuffer(cub);
	file_parce(argc, argv, cub);
	cub->screen = new_pic(cub, cub->width, cub->height);
	if (cub->save_bmp == 1)
		ray(cub);
	if (cub->save_bmp == 0)
	{
		cub->win = mlx_new_window(cub->mlx, cub->width, cub->height, "Cub3D");
		if (!cub->win)
			err_exit(2);
		mlx_hook(cub->win, 2, 1L << 0, key_pressed, cub);
		mlx_hook(cub->win, 3, 1L << 1, key_released, cub);
		mlx_hook(cub->win, 17, 1L << 17, event_destroy_window, cub);
		mlx_loop_hook(cub->mlx, loop, cub);
		mlx_loop(cub->mlx);
	}
	return (0);
}
