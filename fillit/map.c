/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:41:16 by amanchon          #+#    #+#             */
/*   Updated: 2016/04/04 17:55:37 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		*new_map(int size)
{
	int		i;
	t_map	*map;

	i = 0;
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	map->size = size;
	if (!(map->data = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		if (!(map->data[i] = (char*)malloc(sizeof(char) * size + 1)))
			return (NULL);
		ft_memset(map->data[i], '.', size);
		map->data[i][size] = '\0';
		i++;
	}
	return (map);
}

void		free_map(t_map **map)
{
	int		i;

	i = 0;
	if (*map)
	{
		if ((*map)->data)
		{
			while (i < (*map)->size)
			{
				free((*map)->data[i]);
				i++;
			}
			free((*map)->data);
			(*map)->data = NULL;
		}
		free(*map);
		*map = NULL;
	}
}

int			print_map(t_map *map)
{
	int		x;

	x = 0;
	while (x < map->size)
	{
		ft_putendl(map->data[x]);
		x++;
	}
	free_map(&map);
	return (1);
}

int			place_tetri(t_tetri *t, t_map *m, t_point *p)
{
	int		i;
	int		j;

	i = 0;
	i = 0;
	while (i < t->width)
	{
		j = 0;
		while (j < t->height)
		{
			if ((t->buffer[j][i] == '#')
				&& (m->data[p->y + j][p->x + i] != '.'))
				return (0);
			j++;
		}
		i++;
	}
	set_value(t, m, p, t->letter);
	return (1);
}

int			set_value(t_tetri *t, t_map *m, t_point *p, char c)
{
	int		i;
	int		j;

	i = 0;
	while (i < t->width)
	{
		j = 0;
		while (j < t->height)
		{
			if (t->buffer[j][i] == '#')
			{
				m->data[p->y + j][p->x + i] = c;
			}
			j++;
		}
		i++;
	}
	return (0);
}
