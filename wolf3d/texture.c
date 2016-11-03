/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 19:06:38 by amanchon          #+#    #+#             */
/*   Updated: 2016/11/03 16:41:56 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*void		assign_tex_bytes(t_env *e, int x, int y)
{

}*/
void		import_texture(t_env *e)
{
	char			*files[8];
	int				w;
	int				h;
	int				f;

	f = -1;
	files[0] = "bluestone.xpm";
	files[1] = "eagle.xpm";
	files[2] = "greystone.xpm";
	files[3] = "mossy.xpm";
	files[4] = "wood.xpm";
	files[5] = "redbrick.xpm";
	files[6] = "colorstone.xpm";
	files[7] = "barrel.xpm";
	while (++f < 7)
	{
	e->texture[f].ptr = mlx_xpm_file_to_image(e->mlx, "bluestone.xpm", &w, &h);
	e->texture[f].pxl = mlx_get_data_addr(e->texture[f].ptr, &e->texture[f].bpp,
			&e->texture[f].line_size, &e->texture[f].endian);
	}
	//e->img = new_img(e, x ,y);
	//ft_putstr("lol");
	//ft_putchar(e->img->pxl[10]);
}

void		init_texture(t_env *e)
{
	int			x;
	int			y;
	int			xorcolor;

	x = 0;
	while (x < TEX_W)
	{
		y = 0;
		while (y < TEX_H)
		{
			xorcolor = (x * 256 / TEX_W) ^ (y * 256 / TEX_H);
			e->textures[0][TEX_W * y + x] = xorcolor;//65536 * 192 * (x % 32 && y % 16;
			e->textures[1][TEX_W * y + x] = 256 * xorcolor;
			e->textures[2][TEX_W * y + x] = xorcolor + 65536 * xorcolor;
			e->textures[3][TEX_W * y + x] = 256 * xorcolor + 65536 * xorcolor;
			//e->textures[4][TEX_W * y + x] = 256 * xorcolor + xorcolor;
			//e->textures[2][TEX_W * y + x] = 0x00abc5 * xorcolor;
			//e->textures[3][TEX_W * y + x] = 127 + 63.5 * (sin(x + 5) + sin(y + 5));
			e->textures[4][TEX_W * y + x] = 0x0f0f43 * xorcolor;
			e->textures[5][TEX_W * y + x] = xorcolor + 256 * xorcolor
				+ 65536 * xorcolor;
			y++;
		}
		x++;
	}
	import_texture(e);
}


void		test_tex(t_env *e)
{
	int				x;
	int				y;
	//e->img = new_img(e, WIN_W, WIN_H);
	//init_texture(e);
	import_texture(e);
	x = 0;
	while (x < TEX_W)
	{
		y = 0;
		while (y < TEX_H)
		{
	//		img_put_pixel(e, x, y, e->textures[2][TEX_W * y + x]);
	//		img_put_pixel(e, x, y + 200, e->textures[3][TEX_W * y + x]);
	//		img_put_pixel(e, x, y + 400, e->textures[4][TEX_W * y + x]);
			y++;
		}
		x++;
	}
}

void		draw_floor_and_sky(t_env *e)
{
	int		y;

	y = 0;
	while (y < WIN_H)
	{
		if (y < e->line_lim[0])
			img_put_pixel(e, e->screen_coord[0], y, 0x66ccdc);
		if (y > e->line_lim[1])
			img_put_pixel(e, e->screen_coord[0], y, 0x390a0a);
		y++;
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
	draw_floor_and_sky(e);
	while (e->line_lim[0] < e->line_lim[1])
	{
		e->tex[1] = (((e->line_lim[0] * 256 - WIN_H * 128 + e->line_h * 128)
				* TEX_H) / e->line_h) / 256;
		//e->color = e->textures[e->num_tex][TEX_W * e->tex[1] + e->tex[0]];
		e->color = e->texture[0].pxl[TEX_W * e->tex[1] * 3 + e->tex[0] * 3];
		if (e->side == 1)
			e->color = (e->color >> 1) & 835511;
		img_put_pixel(e, e->screen_coord[0], e->line_lim[0], e->color);
		e->line_lim[0]++;
	}
}
