/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 22:22:40 by amanchon          #+#    #+#             */
/*   Updated: 2016/10/28 22:58:35 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "includes/libft.h"
# include "includes/mlx.h"
# include <math.h>

/*
 *KEYBOARD
 */
# define RIGHT 124
# define LEFT 123
# define UP 126
# define DOWN 125
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
}					t_env;

t_img			*new_img(t_env *e, int w, int h);
void			img_put_pixel(t_env *e, int x, int y, int color);
void			img_draw_line(t_env *e, int [2], int b[2], int color);

