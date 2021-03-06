/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 00:19:47 by amanchon          #+#    #+#             */
/*   Updated: 2016/11/18 02:44:15 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "includes/libft.h"
# include "includes/mlx.h"
# include "libft/get_next_line.h"
# define W_HEIGHT 1400
# define W_WIDTH 1400
# define SCALE_MAX 100
# define SCALE_MIN 2

typedef struct	s_img
{
	void		*ptr;
	int			bpp;
	int			line_size;
	int			endian;
	char		*pxl_bytes;
	int			h;
	int			w;
}				t_img;

typedef struct	s_line_data
{
	int			dx;
	int			dy;
	int			ix;
	int			iy;
	int			err;
	int			e;
}				t_line_data;

typedef struct	s_point2d
{
	int			x;
	int			y;
	int			color;
}				t_point2d;

typedef struct	s_point3d
{
	int			x;
	int			y;
	int			z;
}				t_point3d;

typedef struct	s_map
{
	int			h;
	int			w;
	int			**data;
}				t_map;

typedef struct	s_env
{
	void		*mlx;
	void		*wnd;
	t_img		*img;
	t_map		*map;
	int			scale;
	t_point2d	**points;
	int			type;
	int			xoff;
	int			yoff;
	int			zscale;
}				t_env;

t_point2d		*new_2dpoint(int x, int y, int color);
t_point3d		*new_3dpoint(int x, int y, int z);
t_map			*get_map_data(char *file);
void			map_to_2d(t_env *e);
void			draw_image(t_env *e);
void			img_put_pixel(t_env *e, t_point2d *point, int color);
t_img			*new_img(t_env *e, int width, int height);
void			get_scale(t_env *e);
int				refresh_window(t_env *e);
int				key_events(int keycode, t_env *e);
int				get_color(int z);
#endif
