/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 22:24:33 by amanchon          #+#    #+#             */
/*   Updated: 2016/11/07 23:05:59 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		rotate(t_env *e)
{
	double		tmp_dir;
	double		tmp_plan;

	if (e->key_state[1] == 1)
	{
	tmp_dir = e->dir[0];
	tmp_plan = e->plan[0];
		e->dir[0] = e->dir[0] * cos(-e->rotspd) - e->dir[1] * sin(-e->rotspd);
		e->dir[1] = tmp_dir * sin(-e->rotspd) + e->dir[1] * cos(-e->rotspd);
		e->plan[0] = e->plan[0] * cos(-e->rotspd) - e->plan[1] * sin(-e->rotspd);
		e->plan[1] = tmp_plan * sin(-e->rotspd) + e->plan[1] * cos(-e->rotspd);
	}
	if (e->key_state[3] == 1)
	{
	tmp_dir = e->dir[0];
	tmp_plan = e->plan[0];
		e->dir[0] = e->dir[0] * cos(e->rotspd) - e->dir[1] * sin(e->rotspd);
		e->dir[1] = tmp_dir * sin(e->rotspd) + e->dir[1] * cos(e->rotspd);
		e->plan[0] = e->plan[0] * cos(e->rotspd) - e->plan[1] * sin(e->rotspd);
		e->plan[1] = tmp_plan * sin(e->rotspd) + e->plan[1] * cos(e->rotspd);
	}
}

void		move(t_env *e)
{
	//ft_putstr("moving....\n");
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
	if (e->key_state[0] == 1)
	{
		dest[0] = e->pos[0] + e->dir[0] * e->movespd;
		dest[1] = e->pos[1] + e->dir[1] * e->movespd;
		if (!(e->map[(int)dest[0]][(int)e->pos[1]]))
			e->pos[0] += e->dir[0] * e->movespd;
		if (!(e->map[(int)e->pos[0]][(int)dest[1]]))
			e->pos[1] += e->dir[1] * e->movespd;
	}
	if (e->key_state[2] == 1)
	{
		dest[0] = e->pos[0] - e->dir[0] * e->movespd;
		dest[1] = e->pos[1] - e->dir[1] * e->movespd;
		if (!(e->map[(int)dest[0]][(int)e->pos[1]]))
			e->pos[0] -= e->dir[0] * e->movespd;
		if (!(e->map[(int)e->pos[0]][(int)dest[1]]))
			e->pos[1] -= e->dir[1] * e->movespd;
	}
}

void		manage_map(t_env *e, int mode)
{
	t_iarr dest;
	//dest[0] = (int)e->pos[0] + e->dir[0] + e->cam_pos > e->pos[0] + 1 ?
	//	(int)e->pos[0] + e->dir[0] : (int)e->pos[0] + e->dir[0] + e->cam_pos;
	//dest[1] = (int)e->pos[1] + e->dir[1] + e->cam_pos > e->pos[1] + 1 ?
	//	(int)e->pos[1] + e->dir[1]: (int)e->pos[1] + e->dir[1] + e->cam_pos;
	dest[0] = (int)e->pos[0] + e->dir[0] + (double)WIN_W / WIN_W - 1;
	dest[1] = (int)e->pos[1] + e->dir[1] + (double)WIN_H / WIN_H - 1;
		if (dest[0] == MAP_SIZE - 1 || dest[0] == 1 ||
			dest[1] ==  MAP_SIZE - 1 || dest[1] == 1)
		return ;
	ft_putstr("[");
	ft_putnbr(dest[0]);
	ft_putstr(", ");
	ft_putnbr(dest[1]);
	ft_putstr("] = ");
	ft_putnbr(e->map[dest[0]][dest[1]]);
	ft_putstr("\n");
	if (mode == 1)
		e->map[dest[0]][dest[1]] = (e->map[dest[0]][dest[1]] + 1) % 8;
	if (mode == 0)
		e->map[dest[0]][dest[1]] = 0;
}

void		print_data(t_env *e)
{
	mlx_string_put(e->mlx, e->wnd, 100, 100, 0xFFFFFF, "Position:");
	mlx_string_put(e->mlx, e->wnd, 200, 100, 0x00ffffff, ft_itoa(e->pos[0]));
	mlx_string_put(e->mlx, e->wnd, 250, 100, 0x00ffffff, ft_itoa(e->pos[1]));
	mlx_string_put(e->mlx, e->wnd, 100, 200, 0xFFFFFF, "Direction:");
	mlx_string_put(e->mlx, e->wnd, 200, 200, 0x00ffffff, ft_itoa(e->dir[0]));
	mlx_string_put(e->mlx, e->wnd, 250, 200, 0x00ffffff, ft_itoa(e->dir[1]));
}

int			key_hook_release(int key, t_env *e)
{
	if (key == T)
		manage_map(e, 1);
	if (key == R)
		manage_map(e, 0);
	if (key == UP)
		e->key_state[0] = 0;
	if (key == RIGHT)
		e->key_state[1] = 0;
	if (key == DOWN)
		e->key_state[2] = 0;
	if (key == LEFT)
		e->key_state[3] = 0;
	return (0);
}

int			key_hook_press(int key, t_env *e)
{
	//ft_putnbr(key);
	//ft_putendl("");
	if (key == UP)
		e->key_state[0] = 1;
	if (key == RIGHT)
		e->key_state[1] = 1;
	if (key == DOWN)
		e->key_state[2] = 1;
	if (key == LEFT)
		e->key_state[3] = 1;
	return (0);
}


int			refresh_window(t_env *e)
{
	move(e);
	rotate(e);
	draw_view(e);
	//test_tex(e);
	mlx_clear_window(e->mlx, e->wnd);
	mlx_put_image_to_window(e->mlx, e->wnd, e->img->ptr, 0, 0);
	//mlx_put_image_to_window(e->mlx, e->wnd, e->texture[0].ptr, 0, 0);
	//print_mini_map(e);
	//print_data(e);
	return (0);
}
