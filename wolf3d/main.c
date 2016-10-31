/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 23:02:46 by amanchon          #+#    #+#             */
/*   Updated: 2016/10/31 22:30:57 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
void		init_map(t_env *e)
{
	int			x;
	int			y;

	y = 0;
	while (y < MAP_SIZE)
	{
		x = 0;
		while (x < MAP_SIZE)
		{
			if (x == MAP_SIZE - 1 || x == 0 || y == MAP_SIZE - 1 || y == 0)
				e->map[y][x] = 1;
			else if (x == 2 && y == 2)
				e->map[y][x] = 2;
			else
				e->map[y][x] = 0;
			x++;
		}
		y++;
	}
	/*e->map = {
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1}
	};*/
}
t_env		*init_env()
{
	t_env		*e;

	if (!(e = (t_env*)ft_memalloc(sizeof(t_env))))
		return (NULL);
	if (!(e->mlx = mlx_init()))
		return (NULL);
	if (!(e->wnd = mlx_new_window(e->mlx, WIN_W, WIN_H, "WOLF42D")))
		return (NULL);
	e->img = new_img(e, WIN_W, WIN_H);
	e->pos[0] = 1;
	e->pos[1] = 1;
	e->dir[0] = -1.0;
	e->dir[1] = 0.0;
	e->plan[0] = 0;
	e->plan[1] = 0.66;
	init_map(e);
	return (e);
}

int			main(void)
{
	t_env		*e;

	if (!(e = init_env()))
		return (1);
	draw_view(e);
	mlx_put_image_to_window(e->mlx, e->wnd, e->img->ptr, 0, 0);
	mlx_loop(e->mlx);
	return (0);
}
