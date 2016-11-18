/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:05:08 by amanchon          #+#    #+#             */
/*   Updated: 2016/11/17 04:47:05 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		img_put_pixel(t_env *e, t_point2d *p, int color)
{
	int		pixel;

	pixel = (p->y + e->yoff) * e->img->line_size
		+ (e->img->bpp / 8) * (p->x + e->xoff);
	if (p->y + e->yoff < W_HEIGHT && p->x + e->xoff < W_WIDTH
			&& p->y + e->yoff > 0 && p->x + e->xoff > 0)
	{
		e->img->pxl_bytes[pixel] = color;
		e->img->pxl_bytes[++pixel] = color >> 8;
		e->img->pxl_bytes[++pixel] = color >> 16;
	}
}

t_img		*new_img(t_env *e, int width, int height)
{
	t_img	*img;

	if (!(img = (t_img*)malloc(sizeof(t_img))))
		return (NULL);
	img->w = width;
	img->h = height;
	img->ptr = mlx_new_image(e->mlx, width, height);
	img->pxl_bytes = mlx_get_data_addr(img->ptr, &img->bpp,
			&img->line_size, &img->endian);
	return (img);
}
