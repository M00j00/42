/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 19:25:08 by amanchon          #+#    #+#             */
/*   Updated: 2016/10/11 20:35:35 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		btn_press(int btn, int x, int y, t_env *e)
{
	if (btn == 1)
	{
		e->resizeX = x;
		e->resizeY = y;
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

//int			mouse_events(int btn, int x, int y, t_env *e)
//{
//	printf("%d x = %d y = %d\nxy = %.4f/%.4f\nXY = %.4f/%.4f\n\n",
			//btn, x, y, e->mandelXMin, e->mandelYMin, e->mandelXMax, e->mandelYMax);
	//return (0);
//}
