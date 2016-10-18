/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 04:23:59 by amanchon          #+#    #+#             */
/*   Updated: 2016/10/15 21:54:57 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env		*init_env(int fractal)
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
	e->btn4 = e->btn5 = 0;
	e->fractal = fractal;
	init_fractal(e);
	return (e);
}

int			get_param(char *str)
{
	if (ft_strequ(str, "mandel"))
		return (0);
	else if (ft_strequ("julia", str))
		return (1);
	else if (ft_strequ("custom", str))
		return (2);
	return (-1);
}

int			main(int argc, char **argv)
{
	t_env *e;

	if (argc != 2 || get_param(argv[1]) == -1)
	{
		ft_putstr("usage: ./fractol [mandel/julia/custom]");
		return (1);
	}
	if (!(e = init_env(get_param(argv[1]))))
		return (1);
	ft_putnbr(e->fractal);
	mlx_hook(e->wnd, ButtonPress, ButtonPressMask, btn_press, e);
	mlx_hook(e->wnd, ButtonRelease, ButtonReleaseMask, btn_release, e);
	//mlx_mouse_hook(e->wnd, mouse_events, e);
	mlx_key_hook(e->wnd, key_events, e);
	mlx_expose_hook(e->wnd, refresh_window, e);
	mlx_loop(e->mlx);
	return (0);
}
