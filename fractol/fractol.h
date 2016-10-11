/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 04:24:15 by amanchon          #+#    #+#             */
/*   Updated: 2016/10/11 19:40:26 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "includes/libft.h"
# include "includes/mlx.h"
# define W_H 1000
# define W_W 1000
# define MANDEL_XMAX 0.6
# define MANDEL_XMIN -2.1
# define MANDEL_YMAX 1.2
# define MANDEL_YMIN -1.2
# define MANDEL_MAX_ITER 50
# define MANDEL_MAX_RADIUS 4
# define RGB_MAX 255
# define MAX_THEME 5
# define MIN_THEME 1

typedef struct		s_img
{
	void			*ptr;
	int				bpp;
	int				line_size;
	int				endian;
	char			*pxl;
}					t_img;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_env
{
	void			*mlx;
	void			*wnd;
	t_img			*img;
	int				iter;
	int				max_iter;
	int				screenX;
	int				screenY;
	int				resizeX;
	int				resizeY;
	int				theme[3];
	double			pxlW;
	double			pxlH;
	double			mandelX;
	double			mandelY;
	double			mandelXMax;
	double			mandelYMax;
	double			mandelYMin;
	double			mandelXMin;
	double			mandelMaxRadius;
	double			Cx;
	double			Cy;
	double			Cx2;
	double			Cy2;
}					t_env;

t_img				*new_img(t_env *e, int w, int h);
void				img_put_pixel(t_env *e, t_point *p, int color);
t_point				*new_point(int x, int y);
double				screen_to_world_coord(t_env *e, int x, int mode, int fractal);
void				draw_mandel(t_env *e);
void				init_mandel(t_env *e);
void				mandelbrot(t_env *e);
int					get_color(t_env *e);
int					key_events(int keycode, t_env *e);
int					mouse_events(int btn, int x, int y, t_env *e);
int					refresh_window(t_env *e);
int					btn_press(int btn, int x, int y, t_env *e);
int					btn_release(int btn, int x, int y, t_env *e);
#endif
