/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 00:20:12 by amanchon          #+#    #+#             */
/*   Updated: 2016/11/18 02:35:45 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_env		*init_env(char *file)
{
	t_env	*e;
	int		y;

	y = 0;
	if (!(e = (t_env*)malloc(sizeof(t_env))))
		return (NULL);
	if (!(e->mlx = mlx_init()))
		return (NULL);
	if (!(e->wnd = mlx_new_window(e->mlx, W_WIDTH, W_HEIGHT, file)))
		return (NULL);
	if (!(e->map = get_map_data(file)))
		return (NULL);
	if (!(e->img = new_img(e, W_WIDTH, W_HEIGHT)))
		return (NULL);
	if (!(e->points = (t_point2d**)malloc(sizeof(t_point2d*) * e->map->h)))
		return (NULL);
	while (y < e->map->h)
		if (!(e->points[y++] = (t_point2d*)malloc(sizeof(t_point2d)
						* e->map->w)))
			return (NULL);
	get_scale(e);
	e->type = 2;
	e->yoff = e->img->h / 2;
	e->xoff = e->img->w / 2;
	return (e);
}

int					main(int argc, char **argv)
{
	t_env	*e;

	if (argc < 2)
		return (0);
	if (!(e = init_env(argv[1])))
		return (0);
	mlx_key_hook(e->wnd, key_events, e);
	mlx_expose_hook(e->wnd, refresh_window, e);
	mlx_loop_hook(e->mlx, refresh_window, e);
	mlx_loop(e->mlx);
	return (0);
}
