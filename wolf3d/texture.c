/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 19:06:38 by amanchon          #+#    #+#             */
/*   Updated: 2016/11/02 07:27:38 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*void		assign_tex_bytes(t_env *e, int x, int y)
{

}*/

void		init_texture(t_env *e)
{
	int		x;
	int		y;
	int		xorcolor;

	x = 0;
	while (x < TEX_W)
	{
		y = 0;
		while (y < TEX_H)
		{
			xorcolor = (x * 256 / TEX_W) ^ (y * 256 / TEX_H);
			e->textures[0][TEX_W * y + x] = 65536 * 192 * (x % 16 && y % 16);
			e->textures[1][TEX_W * y + x] = 256 * xorcolor;
			e->textures[2][TEX_W * y + x] = xorcolor + 256 * xorcolor
				+ 65536 * xorcolor;
			y++;
		}
		x++;
	}
}

void		test_tex(t_env *e)
{
	int		x;
	int		y;

	e->img = new_img(e, WIN_W, WIN_H);
	init_texture(e);
	x = 0;
	while (x < TEX_W)
	{
		y = 0;
		while (y < TEX_H)
		{
			img_put_pixel(e, x, y, e->textures[0][TEX_W * y + x]);
			y++;
		}
		x++;
	}
}

void		draw_texture(t_env *e)
{
	e->num_tex = e->map[e->map_coord[0]][e->map_coord[1]] - 1;
	e->wall_pos = (e->side == 0) ? e->ray_pos[1] + e->perp_dist * e->ray_dir[1]
		: e->ray_pos[0] + e->perp_dist * e->ray_dir[0];
	e->wall_pos -= floor(e->wall_pos);
	e->tex[0] = (int)(e->wall_pos * (double)TEX_W);
	if (e->side == 0 && e->ray_dir[0] > 0)
		e->tex[0] = TEX_W - e->tex[0] - 1;
	if (e->side == 1 && e->ray_dir[1] < 0)
		e->tex[0] = TEX_W - e->tex[0] - 1;
	while (e->line_lim[0] < e->line_lim[1])
	{
		e->tex[1] = (((e->line_lim[0] * 256 - WIN_H * 128 + e->line_h *128)
				* TEX_H) / e->line_h) / 256;
		e->color = e->textures[e->num_tex][TEX_W * e->tex[1] + e->tex[0]];
		if (e->side == 1)
			e->color = (e->color >> 1) & 835511;
		img_put_pixel(e, e->screen_coord[0], e->line_lim[0], e->color);
		printf("pixel: [%d, %d]\tcolor: %d\ttexX: %d\ttexY: %d\n", e->screen_coord[0], e->line_lim[0], e->color, e->tex[0], e->tex[1]);
		e->line_lim[0]++;
	}
}
