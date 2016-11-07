/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 19:06:38 by amanchon          #+#    #+#             */
/*   Updated: 2016/11/07 22:42:47 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		init_texture(t_env *e)
{
	char			*files[8];
	int				w;
	int				h;
	int				f;

	f = -1;
	files[0] = "textures/bluestone.xpm";
	files[1] = "textures/eagle.xpm";
	files[2] = "textures/greystone.xpm";
	//files[3] = "textures/mossy.xpm";
	files[3] = "textures/bricksx64.xpm";
	files[4] = "textures/wood.xpm";
	files[5] = "textures/redbrick.xpm";
	files[6] = "textures/colorstone.xpm";
	files[7] = "textures/barrel.xpm";
	while (++f < 7)
	{
		if ((e->texture[f].ptr = mlx_xpm_file_to_image(e->mlx,
					files[f], &w, &h)) != NULL)
		e->texture[f].pxl = mlx_get_data_addr(e->texture[f].ptr,
				&e->texture[f].bpp, &e->texture[f].line_size,
				&e->texture[f].endian);
		else
			ft_putstr("error texture\n");
	}
}
/*

int			get_average_color(t_env *e, int t, int y, int range)
{
	int		color;
	int		bytes[range * 2];
	int		i;

	i = -range;
	color = 0;
	while (i < range)
	{
		color += img_get_pixel(e, &e->texture[t], e->screen_coord[0], y + i);
		ft_putnbr(color);
		i++;
	}
	color /= range * 2;
	return (color);
}

void		resize_line(t_env *e, int h, int t)
{
	int		colors[h];
	int		i;

	i = 0;
	while (i < h)
	{
		colors[i] =0; 
		i++;
	}
}

void		draw_tex_line(t_env *e, int tex_num, int start, int end)
{
	int		y;
	int		byte;
	int		rate;

	y = start;
	rate = TEX_H / (end - start);
	ft_putnbr(rate);
	ft_putstr("\t");
	while (y < end)
	{
		byte = e->texture[tex_num].line_size *
						y + (e->texture[tex_num].bpp / 8) * e->screen_coord[0];
		y++;
	}
}

void		test_tex(t_env *e)
{
	int				x;
	int				y;
	int				offset;
	int				tex_num;
//	t_color			*c;
	int				r, b, g;
	//e->img = new_img(e, WIN_W, WIN_H);
	//init_texture(e);
	//load_texture(e);
	import_texture(e);
	tex_num = offset = 0;
	//img_put_pixel(e, 50, 50, 0xF0F0F0);
	//img_get_pixel(e, e->img, 50, 50);
	while (tex_num < 7)
	{
		x = 0;
		while (x < TEX_W)
		{
			y = 0;
			while (y < TEX_H)
			{
				//ft_putstr("lel\n");
				//img_put_pixel(e, x, y + offset, e->texture[tex_num]
				//		.pxl[e->texture[tex_num].line_size * y 
				//		+ (e->texture[tex_num].bpp / 8) * x]);
				//img_put_pixel(e, x ,y + offset, img_get_pixel(e, &e->texture[tex_num], x, y));
				y++;
			}
			x++;
		}
	offset += 100;
	tex_num++;
	}
}
*/
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

void		calc_floor_wall_pos(t_env *e)
{
	if (e->side == 0 && e->ray_dir[0] > 0)
	{
		e->floor_lim[0] = e->map_coord[0];
		e->floor_lim[1] = e->map_coord[1] + e->wall_pos;
	}
	else if (e->side == 0 && e->ray_dir[0] < 0)
	{
		e->floor_lim[0] = e->map_coord[0] + 1;
		e->floor_lim[1] = e->map_coord[1] + e->wall_pos;
	}
	else if (e->side == 1 && e->ray_dir[0] > 0)
	{
		e->floor_lim[0] = e->map_coord[0] + e->wall_pos;
		e->floor_lim[1] = e->map_coord[1];
	}
	else
	{
		e->floor_lim[0] = e->map_coord[0];
		e->floor_lim[1] = e->map_coord[1] + 1.0;
	}
}

void		draw_floor(t_env *e)
{
	int		y;
	double	rate;

	calc_floor_wall_pos(e);
	y = e->line_lim[1] + 1;
	e->wall_dist = e->perp_dist;
	e->line_lim[1] = e->line_lim[1] < 0 ? WIN_H : e->line_lim[1];
	while (y < WIN_H)
	{
		e->current_dist = (double)(WIN_H / (2 * y - WIN_H));
		rate = e->current_dist / e->wall_dist;
		e->floor[0] = rate * e->floor_lim[0] + (1.0 - rate) * e->pos[0];
		e->floor[1] = rate * e->floor_lim[1] + (1.0 - rate) * e->pos[1];
		e->tex[0] = (int)(e->floor[0] * TEX_W) % TEX_W;
		e->tex[1] = (int)(e->floor[1] * TEX_W) % TEX_W;
		img_put_pixel(e, e->screen_coord[0], y, img_get_pixel(e,
					&e->texture[3], e->tex[0], e->tex[1]));
		img_put_pixel(e, e->screen_coord[0], WIN_H - y, img_get_pixel(e,
					&e->texture[3], e->tex[0], e->tex[1]));
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
	e->tex[0] = ((e->side == 0 && e->ray_dir[0] > 0) ||
			(e->side == 1 && e->ray_dir[1])) ? TEX_W - e->tex[0] -1 : e->tex[0];
	draw_floor_and_sky(e);
	while (e->line_lim[0] < e->line_lim[1])
	{
		e->tex[1] = (((e->line_lim[0] * 256 - WIN_H * 128 + e->line_h * 128)
				* TEX_H) / e->line_h) / 256;
		e->color = img_get_pixel(e, &e->texture[e->num_tex],
				e->tex[0], e->tex[1]);
		//if (e->side == 1)
		//	e->color = (e->color >> 1) & 835511;
		img_put_pixel(e, e->screen_coord[0], e->line_lim[0], e->color);
		e->line_lim[0]++;
	}
}
