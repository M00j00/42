/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 15:02:16 by amanchon          #+#    #+#             */
/*   Updated: 2016/10/12 23:09:49 by amanchon         ###   ########.fr       */
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
		e->xoff -= 1;
	if (key == LEFT)
		e->xoff += 1;
	if (key == UP)
		e->yoff += 1;
	if (key == DOWN)
		e->yoff -= 1;
	if (key == ZOOMIN)
		e->jzoom += 2;
	if (key == ZOOMOUT && e->jzoom >= 3)
		e->jzoom -= 2;
}

int			key_events(int keycode, t_env *e)
{
	ft_putnbr(keycode);
	ft_putchar('\n');
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
	if (!(e->img = new_img(e, W_W, W_H)))
		exit(1);
	if (e->fractal == 0)
		draw_mandel(e);
	if (e->fractal == 1)
		draw_julia(e);
	if (e->fractal == 2)
		;
	mlx_clear_window(e->mlx, e->wnd);
	mlx_put_image_to_window(e->mlx, e->wnd, e->img->ptr, 0, 0);
	return (0);
}
