/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 19:56:17 by amanchon          #+#    #+#             */
/*   Updated: 2016/11/07 23:04:45 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		init_map(t_env *e)
{
	int			x;
	int			y;
	int			tex;

	tex = 0;
	y = 0;
	while (y < MAP_SIZE)
	{
		x = 0;
		while (x < MAP_SIZE)
		{
			if (x == MAP_SIZE - 1 || x == 0 || y == MAP_SIZE - 1 || y == 0)
				e->map[x][y] = 1;

			//else if (y == MAP_SIZE - 1 || y == 0 )//|| y == MAP_SIZE - 1 || y == 0)
			//	e->map[x][y] = 2;
			//else if (x % 5 && y % 3)
			//	e->map[y][x] = tex % 8;
			//else if (x % 2 && y % 5)
			//	e->map[y][x] = 3;
			//else if (x % 3 && y % 7)
			//	e->map[y][x] = 2;
			else if (x == 3 && y == 5)
				e->map[y][x] = 7;
			else
				e->map[x][y] = 0;
			x++;
			tex++;
		}
		y++;
	}
}

void		print_map(t_env *e)
{
	int			x;
	int			y;

	y = 0;
	while (y < MAP_SIZE)
	{
		x = 0;
		while (x < MAP_SIZE)
		{
			if (x == (int)e->pos[0] && y == (int)e->pos[1])
				ft_putchar('x');
			else
				ft_putnbr(e->map[x][y]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
	ft_putstr("\n\n\n");
}

void		load_map()
{
	char	*line;
	int		fd;

	//if (!(fd))
}

void		print_mini_map(t_env *e)
{
	int		x;
	int		y;

	x = e->pos[0] - 10;
	while (x < e->pos[0] + 10)
	{
		y = e->pos[1] - 10;
		while (y < e->pos[1] +10)
		{
			if (x < MAP_SIZE && x > 0 && y < MAP_SIZE && y > 0)
				e->map[x][y] > 0 ? mlx_string_put(e->mlx, e->wnd,
						100 + x * 3, 100 + y * 3, 0x000000, " ") :
					mlx_string_put(e->mlx, e->wnd, (100 + x) * 3, (100 + y) * 3,
							0xFFFFFF, "W");
			y++;
		}
		x++;
	}
}
