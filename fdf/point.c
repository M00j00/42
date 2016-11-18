/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 05:45:55 by amanchon          #+#    #+#             */
/*   Updated: 2016/11/18 02:51:22 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_point2d			*new_2dpoint(int x, int y, int color)
{
	t_point2d		*p;

	if (!(p = (t_point2d*)malloc(sizeof(t_point2d))))
		return (NULL);
	p->x = x;
	p->y = y;
	p->color = color;
	return (p);
}

t_point3d			*new_3dpoint(int x, int y, int z)
{
	t_point3d		*p;

	if (!(p = (t_point3d*)malloc(sizeof(t_point3d))))
		return (NULL);
	p->x = x;
	p->y = y;
	p->z = z;
	return (p);
}

int					get_color(int z)
{
	int				color;

	if (z <= 3)
		color = 0x0D6386;
	if (z > 3 && z <= 10)
		color = 0xFDCE08;
	if (z > 10 && z <= 30)
		color = 0x797E1C;
	if (z > 30 && z <= 45)
		color = 0x616516;
	if (z > 45)
		color = 0x5D3227;
	return (color);
}

static t_point2d	*get_coord(t_env *e, t_point3d *p)
{
	t_point2d		*r;
	int				avlen;
	int				sin120;

	sin120 = sqrt(3) / 2;
	avlen = (W_WIDTH + W_HEIGHT) / 2;
	if (e->type == 0)
		r = new_2dpoint(p->x - e->zscale * p->z,
				p->y + (p->x + e->zscale * p->z) / 2, get_color(p->z));
	if (e->type == 1)
		r = new_2dpoint((p->x + e->zscale * p->z) / sqrt(2),
				(2 * p->y + e->zscale * p->z) / sqrt(6),
				get_color(p->z));
	if (e->type == 2)
		r = new_2dpoint(p->x - p->y / 2, p->y / 2 - e->zscale * p->z,
				get_color(p->z));
	return (r);
}

void				map_to_2d(t_env *e)
{
	int				x;
	int				y;
	t_point3d		*tmp;

	y = 0;
	while (y < e->map->h)
	{
		x = 0;
		while (x < e->map->w)
		{
			tmp = new_3dpoint(x * e->scale, y * e->scale, e->map->data[y][x]);
			e->points[y][x] = *get_coord(e, tmp);
			free(tmp);
			x++;
		}
		y++;
	}
}
