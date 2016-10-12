/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 04:24:15 by amanchon          #+#    #+#             */
/*   Updated: 2016/10/12 23:09:35 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "includes/libft.h"
# include "includes/mlx.h"
/*
 * TAILLE DE KA FENETRE
 */
# define W_H 1000
# define W_W 1000
/*
 * CONSTANTES MANDEL
 */
# define MANDEL_XMIN -2.1
# define MANDEL_YMIN -1.2
# define MANDEL_XMAX 0.6
# define MANDEL_YMAX 1.2
# define MANDEL_MAX_ITER 50
# define MANDEL_MAX_RADIUS 4
# define JULIA_R -0.8;
# define JULIA_I 0.2;
/*
 * CONSTANTES COULEUR
 */
# define RGB_MAX 255
/*
 * CONSTANTES EVENT/MASK
 */
# define ButtonPressMask (1L<<2)
# define ButtonReleaseMask (1L<<3)
# define ButtonPress 4
# define ButtonRelease 5
# define MotionNotify 6
/*
 * KEYBOARD
 */
# define R 15
# define F 3
# define T 17
# define G 5
# define Y 16
# define H 4
# define WHEEL_LOCK 82
# define RIGHT 124
# define LEFT 123
# define UP 126
# define DOWN 125
# define ESC 53
# define ZOOMIN 69
# define ZOOMOUT 78

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
	int				fractal;
	int				iter;
	int				max_iter;
	int				screenX;
	int				screenY;
	int				resizeX;
	int				resizeY;
	int				btn5;
	int				btn4;
	int				theme[3];
	int				xoff;
	int				yoff;
	int				jzoom;
	int				wheelock;
	double			pxlW;
	double			pxlH;
	double			mandelX;
	double			mandelY;
	double			juliaX;
	double			juliaY;
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
void				img_put_pixel(t_env *e, int x, int y, int color);
double				screen_to_world_coord(t_env *e, int x, int mode, int fractal);
void				draw_mandel(t_env *e);
void				init_fractal(t_env *e);
void				mandelbrot(t_env *e);
void				draw_julia(t_env *e);
int					get_color(t_env *e);
int					key_events(int keycode, t_env *e);
int					mouse_events(int btn, int x, int y, t_env *e);
int					refresh_window(t_env *e);
int					btn_press(int btn, int x, int y, t_env *e);
int					btn_release(int btn, int x, int y, t_env *e);
#endif
