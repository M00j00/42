/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 23:02:46 by amanchon          #+#    #+#             */
/*   Updated: 2016/11/07 23:09:35 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*TODO
 *
 * fix les textures
 * add des mechants/objet (si color == noir ne pas display)
 * implementer les stats des personnages
 * add une arme/tirer
 *
 *CHASSE AU MALLOC ATTRAPEZ LES TOUS!!
 *
 */

#include "wolf3d.h"

t_env		*init_env()
{
	t_env		*e;

	if (!(e = (t_env*)ft_memalloc(sizeof(t_env))))
		return (NULL);
	if (!(e->mlx = mlx_init()))
		return (NULL);
	if (!(e->wnd = mlx_new_window(e->mlx, WIN_W, WIN_H, "WOLF42D")))
		return (NULL);
	if (!(e->img = new_img(e, WIN_W, WIN_H)))
		return (NULL);
	e->pos[0] = 2;
	e->pos[1] = 6;
	e->dir[0] = -1;
	e->dir[1] = 0;
	e->plan[0] = 0.00;
	e->plan[1] = 0.66;
	e->movespd = 0.1;
	e->rotspd = 0.05;
	e->key_state[0] = e->key_state[1] = e->key_state[2] = e->key_state[3] = 0;
	init_map(e);
	init_texture(e);
	return (e);
}

int			main(void)
{
	t_env		*e;

	if (!(e = init_env()))
		return (1);
	//test_tex(e);
	mlx_loop_hook(e->mlx, refresh_window, e);
	mlx_hook(e->wnd, KEY_PRESS, KEY_PRESS_MASK, key_hook_press, e);
	mlx_hook(e->wnd, KEY_RELEASE, KEY_RELEASE_MASK, key_hook_release, e);
	//mlx_key_hook(e->wnd, key_hook, e);
	mlx_expose_hook(e->wnd, refresh_window, e);
	mlx_loop(e->mlx);
	return (0);
}
