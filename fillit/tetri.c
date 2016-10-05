/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 15:24:44 by amanchon          #+#    #+#             */
/*   Updated: 2016/04/04 17:57:59 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

char		**crop_tetri(char **tmp, t_point *min, t_tetri *t)
{
	int		x;
	int		y;
	int		var;
	char	**buff;

	x = 0;
	var = 0;
	buff = (char**)malloc(sizeof(char**) * (t->height + 1));
	while (var <= t->height)
		buff[var++] = (char*)malloc(sizeof(char*) * (t->width + 1));
	while (x < t->height)
	{
		y = 0;
		while (y < t->width)
		{
			buff[x][y] = tmp[x + min->x][y + min->y];
			y++;
		}
		buff[x][y] = '\0';
		x++;
	}
	buff[x] = NULL;
	return (buff);
}

void		get_dim(t_tetri *t, t_point *min, t_point *max)
{
	int			x;
	int			y;

	x = 0;
	while (t->tmp[x])
	{
		y = -1;
		while (t->tmp[x][++y])
		{
			if (t->tmp[x][y] == '#')
			{
				if (min->x > x)
					min->x = x;
				if (min->y > y)
					min->y = y;
				if (max->x < x)
					max->x = x;
				if (max->y < y)
					max->y = y;
			}
		}
		x++;
	}
	t->height = (max->x - min->x) + 1;
	t->width = (max->y - min->y) + 1;
}

t_tetri		*new_tetri(char *str, char c)
{
	t_point		*max;
	t_point		*min;
	t_tetri		*t;

	if (!(verif_map(str)))
		return (NULL);
	if (!(t = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	if (!(max = new_point(0, 0)))
		return (NULL);
	if (!(min = new_point(3, 3)))
		return (NULL);
	t->letter = c;
	t->tmp = ft_strsplit(str, '\n');
	get_dim(t, min, max);
	t->buffer = crop_tetri(t->tmp, min, t);
	return (t);
}

t_list		*create_list(char *str)
{
	t_tetri		*t;
	t_list		*list;
	char		**tab;
	char		c;

	list = NULL;
	c = 'A';
	if (str[ft_strlen(str) - 1] == '\t')
		return (NULL);
	tab = ft_strsplit(str, '\t');
	while (*tab)
	{
		if (!(t = new_tetri(*tab++, c++)))
			return (NULL);
		if (!(list))
			list = ft_lstnew(t, sizeof(t_tetri));
		else
			ft_lstadd(&list, ft_lstnew(t, sizeof(t_tetri)));
	}
	return (list);
}
