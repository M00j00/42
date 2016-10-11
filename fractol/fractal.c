/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 17:41:33 by amanchon          #+#    #+#             */
/*   Updated: 2016/10/11 18:50:04 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void		init_mandel(t_env *e)
{
	e->mandelXMin = -2.1;
	e->mandelXMax = 0.6;
	e->mandelYMin = -1.2;
	e->mandelYMax = 1.2;
	e->max_iter = 400;
	e->mandelMaxRadius = 4.0;
}

void		mandelbrot(t_env *e)
{
	e->Cx = 0.0;
	e->Cy = 0.0;
	e->Cx2 = 0.0;
	e->Cy2 = 0.0;
	e->iter = 0;
	while (e->iter < e->max_iter && (e->Cx2 + e->Cy2) < e->mandelMaxRadius)
	{
		e->Cy = 2 * e->Cx * e->Cy + e->mandelY;
		e->Cx = e->Cx2 - e->Cy2 + e->mandelX;
		e->Cx2 = e->Cx * e->Cx;
		e->Cy2 = e->Cy * e->Cy;
		e->iter++;
	}
}

void		draw_mandel(t_env *e)
{
	//e->pxlW = (e->mandelXMax - e->mandelXMin) / W_W;
	//e->pxlH = (e->mandelYMax - e->mandelYMin) / W_H;
	e->pxlH = e->pxlW = (((e->mandelXMax - e->mandelXMin) / W_W) +
			((e->mandelYMax - e->mandelYMin) / W_H)) / 2;
	e->screenY = 0;
	while (e->screenY < W_H)
	{
		e->mandelY = e->mandelYMin + e->screenY * e->pxlH;
		if (fabs(e->mandelY) < (e->pxlH / 2))
			e->mandelY = 0.0;
		e->screenX = 0;
		while (e->screenX < W_W)
		{
			e->mandelX = e->mandelXMin + e->screenX * e->pxlW;
			mandelbrot(e);
			img_put_pixel(e, new_point(e->screenX, e->screenY), get_color(e));
			e->screenX++;
		}
		e->screenY++;
	}
}
