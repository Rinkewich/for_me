/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleaf <bleaf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:36:13 by ameteori          #+#    #+#             */
/*   Updated: 2022/11/06 23:36:40 by bleaf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ver_line_color_pic(t_line *line, t_cub *cub, int color)
{
	int	y;
	int	y_max;

	if (line->y0 < line->y1)
	{
		y = line->y0;
		y_max = line->y1;
	}
	else
	{
		y = line->y1;
		y_max = line->y0;
	}
	if (y >= 0)
	{
		while (y < y_max)
		{
			cub->screen->data[y * cub->screen->width + line->x] = color;
			y++;
		}
	}
}

static void	texture_on_screen(t_line *line, t_pic *texture,
								t_cub *cub, t_ray *ray)
{
	int	d;

	d = line->y * texture->width - cub->height * texture->width / 2
		+ ray->line_height * texture->width / 2;
	line->tex_y = \
		((d * texture->height) / ray->line_height) / texture->width;
	cub->screen->data[line->y * cub->screen->width + line->x] = \
		texture->data[line->tex_y * texture->width + line->tex_x];
}

void	ver_line_texture_pic(t_line *line, t_cub *cub,
							t_pic *texture, t_ray *ray)
{
	int	y_max;

	if (line->y0 < line->y1)
	{
		line->y = line->y0;
		y_max = line->y1;
	}
	else
	{
		line->y = line->y1;
		y_max = line->y0;
	}
	if (line->y >= 0)
	{
		while (line->y < y_max)
		{
			texture_on_screen(line, texture, cub, ray);
			line->y++;
		}
	}
}

t_pic	*new_pic(t_cub *cub, int x_len, int y_len)
{
	t_pic	*screen;

	screen = ft_calloc(sizeof(t_pic), 1);
	if (!screen)
		return ((void *)0);
	screen->img = mlx_new_image(cub->mlx, x_len, y_len);
	if (!screen->img)
		return ((void *)0);
	screen->data = (int *)mlx_get_data_addr(screen->img, &screen->bpp,
			&screen->size, &screen->endian);
	screen->width = x_len;
	screen->height = y_len;
	return (screen);
}
