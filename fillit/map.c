/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:41:16 by amanchon          #+#    #+#             */
/*   Updated: 2016/03/16 16:42:57 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		*new_map(int size)
{
	int		i;

	i = 0;
	t_map	*map;
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	map->size = size;
	if (!(map->data = (char**)malloc(sizeof(char*) * size + 1)))
		return (NULL);
	while (i < size)
	{
		if (!(map->data[i] = (char*)malloc(sizeof(char) * size + 1)))
			return (NULL);
		ft_memset(map->data[i], '.', size);
		map->data[i][size] = '\0';
		i++;
	}
	map->data[i] = NULL;
	printf("Map created size = %d x %d\n", size, size);
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
	printf("map freed\n");
}

void		print_map(t_map *map)
{
	int		x;

	x = 0;
	while (x < map->size)
	{
		ft_putnbr(x);
		ft_putstr("--");
		ft_putendl(map->data[x]);
		x++;
	}
}

int		place_tetri(t_tetri *t, t_map *m, t_point *p)
{
	int		i;
	int		j;
	i = 0;
	i = 0;
	while (i < t->width/* && p->x + i < m->size*/)
	{
		j = 0;
		while (j < t->height/* && p->y + j < m->size*/)
		{
			if ((t->buffer[j][i] == '#')
				&& (m->data[p->y + j][p->x + i] != '.'))
			{
				//free(p);
				//ft_putendl("Can't place tetri");
				return (0);
			}
			j++;
		}
		i++;
	}
	//printf("Tetri placed at: ");
	set_value(t, m, p, t->letter);
	return (1);
}

int		set_value(t_tetri *t, t_map *m, t_point *p, char c)
{
	int		i;
	int		j;

	i = 0;
//	printf("\n%s\n%s\n%s\n", t->buffer[0], t->buffer[1], t->buffer[2]);
	while (i < t->width/* && p->x + i < m->size*/)
	{
		j = 0;
		while (j < t->height/* && p->y + j < m->size*/)
		{
			//printf("pos = [%d,%d]\n", p->x + i, p->y + j);
				//printf("setting positon [%d,%d]  t->buffer[%d,%d]=%c\n", p->y + j, p->x + i, j, i, t->buffer[j][i]);
			if (t->buffer[j][i] == '#')
			{
				m->data[p->y + j][p->x + i] = c;
			}
			j++;
		}
		i++;
	}
	//printf("[%d][%d]\n", p->x, p->y);
	//free(p);
	return (0);
}
/*
int main()
{
	t_map *map = new_map(3);
	t_tetri *t = new_tetri(".#\n##\n#.", 'A');
	t_tetri *t2 = new_tetri(".#\n##\n#.", 'A');
	place_tetri(t, map, new_point(0,0));
	set_value(t, map, new_point(0, 0), '.');
	place_tetri(t, map, new_point(0,0));
	print_map(map);
	free_map(&map);
	//getchar("press any key to close");
}*/
