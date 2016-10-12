/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 04:39:03 by amanchon          #+#    #+#             */
/*   Updated: 2016/10/12 19:35:57 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//int			check_bound
int			get_color(t_env *e)
{
	int		color;
	int		i;

	i = (e->iter * 1000) / e->max_iter;
	color = 0x00000000;
	color += (i % RGB_MAX) * e->theme[2]
		+ ((i % RGB_MAX) * e->theme[0] << 8)
		+ ((i % RGB_MAX) * e->theme[1] << 16);

	return (color);
}

double		screen_to_world_coord(t_env *e, int x, int mode, int fractal)
{
	if (fractal == 0)
	{
		if (mode == 0)
			return (e->mandelXMin + x * e->pxlW);
		if (mode == 1)
			return (e->mandelYMin + x * e->pxlH);
	}
	return (-1);
}

void		img_put_pixel(t_env *e, int x, int y, int color)
{
	int		byte;

	byte = y * e->img->line_size
		+ (e->img->bpp/8) * x;
	if (y < W_H && x < W_W && y  > 0 && x > 0)
	{
		e->img->pxl[byte] = color;
		e->img->pxl[++byte] = color >> 8;
		e->img->pxl[++byte] = color >> 16;
	}
}

t_img		*new_img(t_env *e, int width, int height)
{
	t_img	*img;

	if (!(img = (t_img*)malloc(sizeof(t_img))))
		return (NULL);
	img->ptr = mlx_new_image(e->mlx, width, height);
	img->pxl = mlx_get_data_addr(img->ptr, &img->bpp,
			&img->line_size, &img->endian);
	return (img);
}
