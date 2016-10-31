/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 22:22:40 by amanchon          #+#    #+#             */
/*   Updated: 2016/10/31 22:35:07 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "includes/libft.h"
# include "includes/mlx.h"
# include <math.h>

# define WIN_W 800
# define WIN_H 800
# define TEX_H 64
# define TEX_W 64
# define MAP_SIZE 8
/*
 *KEYBOARD
 */
# define RIGHT 124
# define LEFT 123
# define UP 126
# define DOWN 125

typedef double		t_darr[2];
typedef int			t_iarr[2];
typedef int			t_textures[3][TEX_H * TEX_W];
typedef struct		s_img
{
	void		*ptr;
	int			bpp;
	int			line_size;
	int			endian;
	char		*pxl;
}					t_img;

typedef struct		s_env
{
	void		*mlx;
	void		*wnd;
	t_img		*img;
	t_textures	textures;
	int			map[MAP_SIZE][MAP_SIZE];
	t_darr		pos;
	t_darr		dir;
	t_darr		plan;
	t_darr		ray_pos;
	t_darr		ray_dir;
	t_darr		side_dist;
	t_darr		delta_dist;
	t_iarr		map_coord;
	t_iarr		screen_coord;
	t_iarr		step;
	t_iarr		line_lim;
	t_iarr		tex;
	int			colision;
	int			line_h;
	int			num_tex;
	int			side;
	int			color;
	double		perp_dist;
	double		cam_pos;
	double		movespd;
	double		rotspd;
	double		wall_pos;
}					t_env;

t_img			*new_img(t_env *e, int w, int h);
void			img_put_pixel(t_env *e, int x, int y, int color);
void			img_draw_line(t_env *e, int [2], int b[2], int color);
void			cast_ray(t_env *e, int x);
void			draw_texture(t_env *e);
void			draw_view(t_env *e);
#endif
