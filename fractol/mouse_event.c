/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 19:25:08 by amanchon          #+#    #+#             */
/*   Updated: 2016/10/14 21:34:19 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
void	resize_mandel(t_env *e, int btn, int x, int y)
{
	ft_putstr("\nresize_mandel\n");
	if (btn == 4 || btn == 6)
	{
		e->mandelXMin = screen_to_world_coord(e, x - W_W / 2 - 100, 0, 0);
		e->mandelYMin = screen_to_world_coord(e, y - W_H / 2 - 100, 1, 0);
		e->mandelXMax = screen_to_world_coord(e, x + W_W / 2 + 100, 0, 0);
		e->mandelYMax = screen_to_world_coord(e, y + W_H / 2 + 100, 1, 0);
		e->btn4 = 0;
	}
	else if (btn == 5 || btn == 7)
	{
		e->mandelXMin = screen_to_world_coord(e, x - W_W / 2 + 100, 0, 0);
		e->mandelYMin = screen_to_world_coord(e, y - W_H / 2 + 100, 1,0);
		e->mandelXMax = screen_to_world_coord(e, x + W_W / 2 - 100, 0, 0);
		e->mandelYMax = screen_to_world_coord(e, y + W_H / 2 - 100, 1,0);
		e->btn5 = 0;
	}
}

int		btn_press(int btn, int x, int y, t_env *e)
{
	ft_putstr("btn_press ");
	ft_putnbr(btn);
	if (btn == 1 && e->fractal == 0)
	{
		e->resizeX = x;
		e->resizeY = y;
	}
	if (btn == 4 && (++e->btn4 > 3) && (e->fractal == 0))
		resize_mandel(e, btn, x, y);
	else if (btn == 5 && (++e->btn5 > 3) && (e->fractal == 0))
		resize_mandel(e, btn, x, y);
	else if (btn == 4 && (e->fractal == 1) && (e->juliaR < 1))
		e->juliaR += 0.1;
	else if (btn == 5 && (e->fractal == 1) && (e->juliaR > 0))
		e->juliaR -= 0.1;
	else
		return (0);
	ft_putstr(" mode: ");
	ft_putnbr(e->fractal);
	//printf("fractal: %d\tbtn4: %d\tbtn5: %d\t", e->fractal, e->btn4, e->btn5);
	ft_putstr(" btn_press\n");
	refresh_window(e);
	return (0);
}

int			btn_release(int btn, int x, int y, t_env *e)
{
	if (btn == 1 && e->resizeX > 0 && e->resizeY > 0)
	{
		e->mandelXMin = screen_to_world_coord(e, e->resizeX, 0, 0);
		e->mandelYMin = screen_to_world_coord(e, e->resizeY, 1, 0);
		e->mandelXMax = screen_to_world_coord(e, x, 0, 0);
		e->mandelYMax = screen_to_world_coord(e, y, 1, 0);
		e->resizeX = -1;
		e->resizeY = -1;
		refresh_window(e);
	}
	return (0);
}


