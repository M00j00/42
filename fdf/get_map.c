/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 07:52:07 by amanchon          #+#    #+#             */
/*   Updated: 2016/10/05 19:08:26 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point2d	*get_coord(t_env *e, t_point3d *p)
{
	t_point2d	*r;
	int		avlen;

	avlen = (W_WIDTH + W_HEIGHT) / 2;
	if (e->type == 0)
	//r = new_2dpoint(p->x + PROJECTION * p->z,
	//p->y + (PROJECTION /2)  * p->z,get_color(p->z));
	r = new_2dpoint((p->x * (avlen / 2)) / (p->z + avlen /2),
			(p->y * (avlen / 2)) / (p->z + avlen /2), get_color(p->z));
	if (e->type == 1)
		r = new_2dpoint((p->x - p->z) / sqrt(2), (p->x + 2 *p->y - p->z) / sqrt(6),
				get_color(p->z));
	/*	r = new_2dpoint(p->x * PROJECTION - p->y * PROJECTION,
				-p->z + PROJECTION * p->x + PROJECTION * p->y,
				get_color(p->z));
	*/if (e->type == 2)
		r = new_2dpoint(p->x - p->y / 2, p->y / 2 - p->z, get_color(p->z));
		return (r);
}

t_point2d	**map_to_2d(t_env *e)
{
	t_point2d	**p;
	int			x;
	int			y;
	t_point3d	*tmp;

	if (!(p = (t_point2d**)malloc(sizeof(t_point2d*) * e->map->h)))
		return (NULL);
	y = 0;
	while (y < e->map->h)
		if (!(p[y++] = (t_point2d*)malloc(sizeof(t_point2d) * e->map->w)))
			return (NULL);
	y = 0;
	while (y < e->map->h)
	{
		x = 0;
		while (x < e->map->w)
		{
			tmp = new_3dpoint(x * e->scale, y * e->scale, e->map->data[y][x]);
			p[y][x] = *get_coord(e, tmp);
			free(tmp);
			x++;
		}
		y++;
	}
	return (p);
}

void		print2dp(t_point2d **p, t_map *m)
{
	int			x;
	int			y;

	y = 0;
	while (y < m->h)
	{
		x = 0;
		while (x < m->w)
		{
			ft_putstr("[");
			ft_putnbr(p[y][x].x);
			ft_putstr(", ");
			ft_putnbr(p[y][x].y);
			ft_putstr("] ");
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
