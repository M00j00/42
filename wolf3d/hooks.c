/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 22:24:33 by amanchon          #+#    #+#             */
/*   Updated: 2016/11/03 16:23:13 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		rotate(t_env *e, int key)
{
	double		tmp_dir;
	double		tmp_plan;

	tmp_dir = e->dir[0];
	tmp_plan = e->plan[0];
	if (key == LEFT)
	{
		e->dir[0] = e->dir[0] * cos(-e->rotspd) - e->dir[1] * sin(-e->rotspd);
		e->dir[1] = tmp_dir * sin(-e->rotspd) + e->dir[1] * cos(-e->rotspd);
		e->plan[0] = e->plan[0] * cos(-e->rotspd) - e->plan[1] * sin(-e->rotspd);
		e->plan[1] = tmp_plan * sin(-e->rotspd) + e->plan[1] * cos(-e->rotspd);
	}
	if (key == RIGHT)
	{
		e->dir[0] = e->dir[0] * cos(e->rotspd) - e->dir[1] * sin(e->rotspd);
		e->dir[1] = tmp_dir * sin(e->rotspd) + e->dir[1] * cos(e->rotspd);
		e->plan[0] = e->plan[0] * cos(e->rotspd) - e->plan[1] * sin(e->rotspd);
		e->plan[1] = tmp_plan * sin(e->rotspd) + e->plan[1] * cos(e->rotspd);
	}
}

void		move(t_env *e, int key)
{
	t_iarr		dest;
/*	ft_putstr("\nmoving.... key: ");
	ft_putnbr(key);
	ft_putstr("\t xdest: ");
	ft_putnbr(e->pos[0] + e->dir[0] * e->movespd);
	ft_putstr("\tydest: ");
	ft_putnbr(e->pos[1] + e->dir[1] * e->movespd);
	ft_putstr("\tvalue: ");
	ft_putnbr(e->map[(int)(e->pos[0] + e->dir[0] * e->movespd)][(int)e->pos[1]]);
	ft_putstr("\t");*/
	if (key == UP)
	{
		dest[0] = e->pos[0] + e->dir[0] * e->movespd;
		dest[1] = e->pos[1] + e->dir[1] * e->movespd;
		if (!(e->map[(int)dest[0]][(int)e->pos[1]]))
			e->pos[0] += e->dir[0] * e->movespd;
		if (!(e->map[(int)e->pos[0]][(int)dest[1]]))
			e->pos[1] += e->dir[1] * e->movespd;
	}
	if (key == DOWN)
	{
		dest[0] = e->pos[0] - e->dir[0] * e->movespd;
		dest[1] = e->pos[1] - e->dir[1] * e->movespd;
		if (!(e->map[(int)dest[0]][(int)e->pos[1]]))
			e->pos[0] -= e->dir[0] * e->movespd;
		if (!(e->map[(int)e->pos[0]][(int)dest[1]]))
			e->pos[1] -= e->dir[1] * e->movespd;
	}
}

void		build(t_env *e){}

void		print_data(t_env *e)
{
	mlx_string_put(e->mlx, e->wnd, 100, 100, 0xFFFFFF, "Position:");
	mlx_string_put(e->mlx, e->wnd, 200, 100, 0x00ffffff, ft_itoa(e->pos[0]));
	mlx_string_put(e->mlx, e->wnd, 250, 100, 0x00ffffff, ft_itoa(e->pos[1]));
	mlx_string_put(e->mlx, e->wnd, 100, 200, 0xFFFFFF, "Direction:");
	mlx_string_put(e->mlx, e->wnd, 200, 200, 0x00ffffff, ft_itoa(e->dir[0]));
	mlx_string_put(e->mlx, e->wnd, 250, 200, 0x00ffffff, ft_itoa(e->dir[1]));
}

int			key_hook(int key, t_env *e)
{
	//ft_putnbr(key);
	move(e, key);
	rotate(e, key);
	refresh_window(e);
	return (0);
}


int			refresh_window(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img->ptr);
	e->img = new_img(e, WIN_W, WIN_H);
	draw_view(e);
	//test_tex(e);
	mlx_clear_window(e->mlx, e->wnd);
	mlx_put_image_to_window(e->mlx, e->wnd, e->img->ptr, 0, 0);
	//mlx_put_image_to_window(e->mlx, e->wnd, e->texture[0].ptr, 0, 0);
	print_map(e);
	print_data(e);
	return (0);
}
