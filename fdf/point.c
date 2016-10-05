/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 05:45:55 by amanchon          #+#    #+#             */
/*   Updated: 2016/09/29 02:41:45 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point2d	*new_2dpoint(int x, int y, int color)
{
	t_point2d		*p;

	if (!(p = (t_point2d*)malloc(sizeof(t_point2d))))
		return (NULL);
	p->x = x;
	p->y = y;
	p->color = color;
	return (p);
}

t_point3d	*new_3dpoint(int x, int y, int z)
{
	t_point3d		*p;

	if (!(p = (t_point3d*)malloc(sizeof(t_point3d))))
		return (NULL);
	p->x = x;
	p->y = y;
	p->z = z;
	return (p);
}
int			get_color(int z)
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
