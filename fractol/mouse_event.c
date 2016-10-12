/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 19:25:08 by amanchon          #+#    #+#             */
/*   Updated: 2016/10/12 23:12:53 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
void	resize_mandel()
{

}

int		btn_press(int btn, int x, int y, t_env *e)
{
	if (btn == 1)
	{
		e->resizeX = x;
		e->resizeY = y;
	}
	if (btn == 4 && ++e->btn4 > 3)
	{
		e->mandelXMin = screen_to_world_coord(e, x - W_W / 2 - 100, 0, 0);
		e->mandelYMin = screen_to_world_coord(e, y - W_H / 2 - 100, 1, 0);
		e->mandelXMax = screen_to_world_coord(e, x + W_W / 2 + 100, 0, 0);
		e->mandelYMax = screen_to_world_coord(e, y + W_H / 2 + 100, 1, 0);
		e->btn4 = 0;
		refresh_window(e);
	}
	if (btn == 5 && ++e->btn5 >3)
	{
		e->mandelXMin = screen_to_world_coord(e, x - W_W / 2 + 100, 0, 0);
		e->mandelYMin = screen_to_world_coord(e, y - W_H / 2 + 100, 1,0);
		e->mandelXMax = screen_to_world_coord(e, x + W_W / 2 - 100, 0, 0);
		e->mandelYMax = screen_to_world_coord(e, y + W_H / 2 - 100, 1,0);
		e->btn5 = 0;
		refresh_window(e);
	}
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


