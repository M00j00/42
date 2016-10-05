/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:23:25 by amanchon          #+#    #+#             */
/*   Updated: 2016/04/04 17:47:16 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <stdio.h>

typedef struct		s_point
{
	int			x;
	int			y;
}					t_point;
typedef struct		s_map
{
	int		size;
	char	**data;
}					t_map;

typedef struct		s_tetri
{
	int			height;
	int			width;
	char		**buffer;
	char		**tmp;
	char		letter;
}					t_tetri;

t_map				*new_map(int size);
void				free_map(t_map **map);
int					print_map(t_map *map);
int					get_mini_map_size(int nb_tetri);
t_point				*new_point(int x, int y);
t_tetri				*new_tetri(char *str, char c);
t_list				*create_list(char *str);
void				print_tetri_list(t_list l);
int					verif_map(char *str);
int					verif_tetri(char *str);
int					verif2_tetri(char *str);
int					try_to_fill(t_map *m, t_list *l);
int					count_elem(t_list *l);
t_map				*resolve(t_list *l);
void				get_dim(t_tetri *t, t_point *min, t_point *max);
int					place_tetri(t_tetri *t, t_map *m, t_point *p);
int					set_value(t_tetri *t, t_map *m, t_point *p, char c);
void				free_list(t_list *l);
void				free_point(t_point *p);
void				del_tetri(t_tetri *t);
void				free_point(t_point *p);

#endif
