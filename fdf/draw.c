/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 07:52:43 by amanchon          #+#    #+#             */
/*   Updated: 2016/10/05 18:53:46 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line_data		*new_ldata(t_point2d a, t_point2d b)
{
	t_line_data		*l;

	if (!(l = (t_line_data*)malloc(sizeof(t_line_data))))
		return (NULL);
	l->dx = ft_abs(b.x - a.x);
	l->dy = ft_abs(b.y - a.y);
	l->ix = (a.x < b.x) ? 1 : -1;
	l->iy = (a.y < b.y) ? 1 : -1;
	l->err = (l->dx > l->dy) ? l->dx / 2 : -l->dy / 2;
	return (l);
}

void			draw_line(t_env *e, t_point2d a, t_point2d b)
{
	t_line_data		*l;

	l = new_ldata(a, b);
	while (42)
	{
		if (b.color < a.color)
			img_put_pixel(e, &a, b.color);
		else
			img_put_pixel(e, &a, a.color);
		if (a.x == b.x && a.y == b.y)
			break ;
		l->e = l->err;
		if (l->e > -l->dx)
		{
			l->err -= l->dy;
			a.x += l->ix;
		}
		if (l->e < l->dy)
		{
			l->err += l->dx;
			a.y += l->iy;
		}
	}
	//free ldata
}

void			get_scale(t_env *e)
{
	e->scale = 0;
	while (e->img->h / 2 > e->map->h * e->scale
				&& e->img->w / 2 > e->map->w * e->scale
				&& e->scale < SCALE_MAX)
		e->scale += 1;
}

void			draw_image(t_env *e, t_point2d **p)
{
	int				x;
	int				y;

	y = 0;
	while (y < e->map->h)
	{
		x = 0;
		while (x < e->map->w)
		{
			if (x == e->map->w - 1 && y == e->map->h - 1)
				;
			else if (x == e->map->w - 1)
				draw_line(e, p[y][x], p[y + 1][x]);
			else if (y == e->map->h - 1)
				draw_line(e, p[y][x], p[y][x + 1]);
			else
			{
				draw_line(e, p[y][x], p[y + 1][x]);
				draw_line(e, p[y][x], p[y][x + 1]);
			}
			x++;
		}
		y++;
	}
}
