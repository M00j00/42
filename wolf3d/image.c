/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 19:52:11 by amanchon          #+#    #+#             */
/*   Updated: 2016/10/31 22:35:06 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		img_put_pixel(t_env *e, int x, int y, int color)
{
	int		byte;

	byte = y * e->img->line_size
		+ (e->img->bpp/8) * x;
	if (y < WIN_H && x < WIN_W && y  > 0 && x > 0)
	{
		e->img->pxl[byte] = color;
		e->img->pxl[++byte] = color >> 8;
		e->img->pxl[++byte] = color >> 16;
	}
}
/*
void		img_draw_line(t_env *e, int x, int y, int x2, int y2)
{
	t_line_data *l;

	l = new_line_data(e, x, y, x2, y2);
	while (42)
	{
		img_put_pixel(e,x, y, e->color);
		if (x == x2 && y == y2)
			break ;
		l->e = l->err;
		if (l->e > -l->dx)
		{
			l->err -= l->dy;
			x += l->ix;
		}
		if (l->e < l->dy)
		{
			l->err += l->dy;
			y += l->iy;
		}
	}
	//free
}*/
void		calc_line_limits(t_env *e)
{
	e->line_h = (int) (WIN_H / e->perp_dist);
	e->line_lim[0] = -e->line_h / 2 + WIN_H / 2;
	e->line_lim[1] = e->line_h / 2 + WIN_H / 2;
	if (e->line_lim[0] < 0)
		e->line_lim[0] = 0;
	if (e->line_lim[1] >= WIN_H)
		e->line_lim[1] = WIN_H - 1;
}

void		draw_view(t_env *e)
{
	e->screen_coord[0] = 0;
	while (e->screen_coord[0] < WIN_W)
	{
		cast_ray(e, e->screen_coord[0]);
		printf("cast_ray x = %d\n", e->screen_coord[0]);
		calc_line_limits(e);
		printf("calc_line_limits %d, %d\n", e->line_lim[0], e->line_lim[1]);
		draw_texture(e);
		printf("draw_texture\n");
		e->screen_coord[0]++;
	}
}

t_img		*new_img(t_env *e, int width, int height)
{
	t_img	*img;

	if (!(img = (t_img*)malloc(sizeof(t_img))))
		return (NULL);
	img->ptr = mlx_new_image(e->mlx, width, height);
	img->pxl = mlx_get_data_addr(img->ptr, &img->bpp,
			&img->line_size, &img->endian);
	return (img);
}
