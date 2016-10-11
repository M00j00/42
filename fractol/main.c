/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 04:23:59 by amanchon          #+#    #+#             */
/*   Updated: 2016/10/11 20:34:43 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env		*init_env()
{
	t_env *e;

	if(!(e = (t_env*)malloc(sizeof(t_env))))
		return (NULL);
	if (!(e->mlx = mlx_init()))
		return (NULL);
	if (!(e->wnd = mlx_new_window(e->mlx, W_W, W_H, "Fractol@42")))
		return (NULL);
	e->img = new_img(e, W_W, W_H);
	e->theme[0] = e->theme[1] = e->theme[2] = 1;
	e->resizeX = e->resizeY = -1;
	init_mandel(e);
	return (e);
}

int			main(int argc, char **argv)
{
	t_env *e;

	if (!(e = init_env()))
		return (0);
	//mlx_hook(e->wnd, BUTTON_PRESS, ButtonPressMask, btn_press, e);
	mlx_mouse_hook(e->wnd, mouse_events, e);
	mlx_key_hook(e->wnd, key_events, e);
	mlx_expose_hook(e->wnd, refresh_window, e);
	mlx_loop(e->mlx);
	return (0);
}
