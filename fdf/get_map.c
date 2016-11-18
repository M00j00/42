/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 07:52:07 by amanchon          #+#    #+#             */
/*   Updated: 2016/11/17 05:07:01 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static t_point2d		*get_coord(t_env *e, t_point3d *p)
{
	t_point2d	*r;
	int			avlen;

	avlen = (W_WIDTH + W_HEIGHT) / 2;
	if (e->type == 0)
		r = new_2dpoint((p->x * (avlen / 2)) / (e->zscale * p->z + avlen / 2),
			(p->y * (avlen / 2)) / (-e->zscale * p->z + avlen / 2),
			get_color(p->z));
	if (e->type == 1)
		r = new_2dpoint((p->x - e->zscale * p->z) / sqrt(2),
				(p->x + 2 * p->y - p->z) / sqrt(6), get_color(p->z));
	if (e->type == 2)
		r = new_2dpoint(p->x - p->y / 2, p->y / 2 - e->zscale * p->z,
				get_color(p->z));
	return (r);
}

void					map_to_2d(t_env *e)
{
	int			x;
	int			y;
	t_point3d	*tmp;

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
