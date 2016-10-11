/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 15:02:16 by amanchon          #+#    #+#             */
/*   Updated: 2016/10/11 19:24:23 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		manage_theme(t_env *e, int key)
{
	if (key == 15 && e->theme[0]++ < MAX_THEME)
		e->theme[0] += 1;
	if (key == 3 && e->theme[0]-- > MIN_THEME)
		e->theme[0] -= 1;
	if (key == 17 && e->theme[1]++ < MAX_THEME)
		e->theme[1] += 1;
	if (key == 5 && e->theme[1]-- > MIN_THEME)
		e->theme[1] -= 1;
	if (key == 16 && e->theme[2]++ < MAX_THEME)
		e->theme[2] += 1;
	if (key == 4 && e->theme[2]-- > MIN_THEME)
		e->theme[2] -= 1;
}

int			key_events(int keycode, t_env *e)
{
	ft_putnbr(keycode);
	manage_theme(e, keycode);
	refresh_window(e);
	return (0);
}

int			mouse_events(int btn, int x, int y, t_env *e)
{
	if (btn == 1 && e->resizeX < 0  && e->resizeY < 0)
	{
		e->resizeX = x;
		e->resizeY = y;
	}
	else if (btn == 1 && e->resizeX >= 0 && e->resizeY >= 0 )
	{
		e->mandelXMin = screen_to_world_coord(e, e->resizeX, 0, 0);
		e->mandelYMin = screen_to_world_coord(e, e->resizeY, 1, 0);
		e->mandelXMax = screen_to_world_coord(e, x, 0, 0);
		e->mandelYMax = screen_to_world_coord(e, y, 1, 0);
		e->resizeX = -1;
		e->resizeY = -1;
		refresh_window(e);
	}
	if (btn == 4)
	{
		
	}
	printf("%d x = %d y = %d\nxy = %.4f/%.4f\nXY = %.4f/%.4f\n\n",
			btn, x, y, e->mandelXMin, e->mandelYMin, e->mandelXMax, e->mandelYMax);
	return 0;
}

int		refresh_window(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img->ptr);
	if (!(e->img = new_img(e, W_W, W_H)))
		exit(1);
	draw_mandel(e);
	mlx_clear_window(e->mlx, e->wnd);
	mlx_put_image_to_window(e->mlx, e->wnd, e->img->ptr, 0, 0);
	ft_putstr("window refresh\n");
	return (0);
}
