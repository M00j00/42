/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 17:41:33 by amanchon          #+#    #+#             */
/*   Updated: 2016/10/18 18:37:27 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//http://paulbourke.net/fractals/burnship/burningship.c
//http://www.cs.utoronto.ca/~noam/fractal.html

#include "fractol.h"
#include <math.h>

void		init_fractal(t_env *e)
{
	e->mandelXMin = MANDEL_XMIN;
	e->mandelXMax = MANDEL_XMAX;
	e->mandelYMin = MANDEL_YMIN;
	e->mandelYMax = MANDEL_YMAX;
	e->max_iter = MANDEL_MAX_ITER;
	e->mandelMaxRadius = MANDEL_MAX_RADIUS;
	e->juliaR = JULIA_R;
	e->juliaI = JULIA_I;
	e->xoff = e->yoff = e->xmid = e->ymid = 0;
	e->jzoom = 1;
	e->N = 4000;
	e->range = 3;
}

void		mandelbrot(t_env *e)
{
	e->Cx = e->Cy = e->Cx2 = e->Cy2 = 0.0;
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
			img_put_pixel(e, e->screenX, e->screenY, get_color(e));
			e->screenX++;
		}
		e->screenY++;
	}
}

void		draw_julia(t_env *e)
{
	e->screenY = 0;
	while (e->screenY < W_H)
	{
		e->screenX = 0;
		while (e->screenX < W_W)
		{
			e->Cx = 1.5 * (e->screenX - W_W / 2) / (0.5 * e->jzoom * W_W)
				+ e->xoff;
			e->Cy = (e->screenY - W_H / 2) / (0.5 * e->jzoom * W_H) + e->yoff;
			e->Cx2 = e->Cx * e->Cx;
			e->Cy2 = e->Cy * e->Cy;
			e->iter = 0;
			while (e->iter < e->max_iter &&
					(e->Cx2 + e->Cy2) < e->mandelMaxRadius)
			{
				e->Cy = 2 * e->Cx *e->Cy + e->juliaI;
				e->Cx = e->Cx2 - e->Cy2 + e->juliaR;
				e->Cx2 = e->Cx * e->Cx;
				e->Cy2 = e->Cy * e->Cy;
				e->iter++;
			}
			img_put_pixel(e, e->screenX, e->screenY, get_color(e));
			e->screenX++;
		}
		e->screenY++;
	}
}

void		draw_burning_ship(t_env *e)
{
	e->screenY = 0;
	while (e->screenY < e->N)
	{
		e->screenX = 0;
		while (e->screenX < e->N)
		{
			e->Cx = 0.0;
			e->Cy = 0.0;
			e->Cx2 = 0.0;
			e->Cy2 = 0.0;
			e->juliaR = e->xmid + 2 * e->range * (e->screenX / (double)e->N - 0.5);
			e->juliaI = e->ymid + 2 * e->range * (e->screenY / (double)e->N - 0.5);
			e->iter = 0;
			while (e->iter < e->max_iter && (e->Cx2 + e->Cy2) < 10)
			{
				e->Cy = 2 * fabs(e->Cx * e->Cy) + e->juliaI;
				e->Cx = e->Cx2 - e->Cy2 + e->juliaR;
				e->Cx2 = e->Cx * e->Cx;
				e->Cy2 = e->Cy * e->Cy;
				e->iter++;
			}
			img_put_pixel(e, e->screenX, e->screenY, get_color(e));
			e->screenX++;
		}
		e->screenY++;
	}
}

void		draw_snowflake(t_env *e)
{

}
