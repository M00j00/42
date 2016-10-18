/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 15:02:16 by amanchon          #+#    #+#             */
/*   Updated: 2016/10/15 21:53:36 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		manage_theme(t_env *e, int key)
{
	if (key == R)
		e->theme[0] += 1;
	if (key == F)
		e->theme[0] -= 1;
	if (key == T)
		e->theme[1] += 1;
	if (key == G)
		e->theme[1] -= 1;
	if (key == Y )
		e->theme[2] += 1;
	if (key == H)
		e->theme[2] -= 1;
	if (key == RIGHT)
		e->xoff -= 0.1 / e->jzoom;
	if (key == LEFT)
		e->xoff += 0.1 / e->jzoom;
	if (key == UP)
		e->yoff += 0.1 / e->jzoom;
	if (key == DOWN)
		e->yoff -= 0.1 / e->jzoom;
	if (key == ZOOMIN)
		e->jzoom *= 2;
if (key == ZOOMOUT && e->jzoom > 1)
		e->jzoom /= 2;
}

int			calc_max_iter(t_env *e)
{
	if (e->fractal == 0)
	{
		e->max_iter = (MANDEL_XMAX - MANDEL_XMIN) * MANDEL_MAX_ITER
			/ (e->mandelXMax - e->mandelXMin);
	}
	if (e->fractal == 1)
	{
		e->max_iter = e->jzoom * MANDEL_MAX_ITER;
	}
	if (e->max_iter > 500)
		e->max_iter = 500;
	if (e->max_iter < 50)
		e->max_iter = 50;
	return (e->max_iter);
}

int			key_events(int keycode, t_env *e)
{
	//ft_putnbr(keycode);
	//ft_putchar('\n');
	manage_theme(e, keycode);
	if (keycode == ESC)
		exit(0);
	if (keycode == WHEEL_LOCK)
		e->wheelock = (e->wheelock == 0) ? 1 : 0;
	refresh_window(e);
	return (0);
}

int		refresh_window(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img->ptr);
	ft_putnbr(calc_max_iter(e));
	ft_putchar('\n');
	calc_max_iter(e);
	if (!(e->img = new_img(e, W_W, W_H)))
		exit(1);
	if (e->fractal == 0)
		draw_mandel(e);
	if (e->fractal == 1)
		draw_julia(e);
	if (e->fractal == 2)
		draw_burning_ship(e);
	mlx_clear_window(e->mlx, e->wnd);
	mlx_put_image_to_window(e->mlx, e->wnd, e->img->ptr, 0, 0);
	return (0);
}
