/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 04:35:50 by amanchon          #+#    #+#             */
/*   Updated: 2016/11/17 07:03:47 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			display_controls(t_env *e)
{
	mlx_string_put(e->mlx, e->wnd, 100, 50, 0xFFFFFF, "Controls:");
	mlx_string_put(e->mlx, e->wnd, 120, 100, 0xFFFFFF,
			"-Fleches pour deplacer l\'image");
	mlx_string_put(e->mlx, e->wnd, 120, 130, 0xFFFFFF,
			"-Numpad + - pour changer l\'echelle");
	mlx_string_put(e->mlx, e->wnd, 120, 160, 0xFFFFFF,
			"-Numpad * / pour changer la profondeur");
	mlx_string_put(e->mlx, e->wnd, 120, 190, 0xFFFFFF,
			"-Espace pour changer la perspective");
	mlx_string_put(e->mlx, e->wnd, 120, 220, 0xFFFFFF,
			"-Echap pour quitter");
}

static void			display_info(t_env *e)
{
	mlx_string_put(e->mlx, e->wnd, 1000, 50, 0xFFFFFF, "Infos:");
	mlx_string_put(e->mlx, e->wnd, 1020, 100, 0xFFFFFF, "Echelle: ");
	mlx_string_put(e->mlx, e->wnd, 1120, 100, 0xFFFFFF, ft_itoa(e->scale));
	mlx_string_put(e->mlx, e->wnd, 1020, 130, 0xFFFFFF, "X offset: ");
	mlx_string_put(e->mlx, e->wnd, 1120, 130, 0xFFFFFF, ft_itoa(e->xoff));
	mlx_string_put(e->mlx, e->wnd, 1020, 160, 0xFFFFFF, "Y offset: ");
	mlx_string_put(e->mlx, e->wnd, 1120, 160, 0xFFFFFF, ft_itoa(e->yoff));
	mlx_string_put(e->mlx, e->wnd, 1020, 190, 0xFFFFFF, "Projection: ");
	if (e->type == 0)
		mlx_string_put(e->mlx, e->wnd, 1150, 190, 0xFFFFFF, "projection 1");
	else if (e->type == 1)
		mlx_string_put(e->mlx, e->wnd, 1150, 190, 0xFFFFFF, "projection 2");
	else
		mlx_string_put(e->mlx, e->wnd, 1150, 190, 0xFFFFFF, "projection 3");
	display_controls(e);
}

int					refresh_window(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img->ptr);
	if (!(e->img = new_img(e, W_WIDTH, W_HEIGHT)))
		exit(1);
	draw_image(e);
	mlx_clear_window(e->mlx, e->wnd);
	mlx_put_image_to_window(e->mlx, e->wnd, e->img->ptr, 0, 0);
	display_info(e);
	return (1);
}

static void			offset_scale_managment(t_env *e, int keycode)
{
	if (keycode == 126)
		e->yoff -= 1000 / e->scale;
	if (keycode == 124)
		e->xoff += 1000 / e->scale;
	if (keycode == 125)
		e->yoff += 1000 / e->scale;
	if (keycode == 123)
		e->xoff -= 1000 / e->scale;
	if (keycode == 69 && e->scale < SCALE_MAX)
		e->scale += 1;
	if (keycode == 78 && e->scale >= SCALE_MIN)
		e->scale -= 1;
	if (keycode == 67 && e->zscale < SCALE_MAX)
		e->zscale += 1;
	if (keycode == 75 && e->zscale >= SCALE_MIN)
		e->zscale -= 1;
}

int					key_events(int keycode, t_env *e)
{
	if (keycode == 49)
	{
		e->type = (e->type + 1) % 3;
	}
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx, e->wnd);
		exit(1);
	}
	offset_scale_managment(e, keycode);
	refresh_window(e);
	return (0);
}
