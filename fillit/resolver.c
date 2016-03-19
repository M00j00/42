/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 15:23:20 by amanchon          #+#    #+#             */
/*   Updated: 2016/03/15 18:58:19 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_mini_map_size(int nb)
{
	int		size;

	nb *= 4;
	size = 0;
	while (size * size < nb)
		size++;
	return (size);
}

int		try_to_fill(t_map *m, t_list *l)
{
	t_tetri		*t;
	t_point		*p;

	if (l->next == NULL)
		return (1);
	p = new_point(0, 0);
	t = (t_tetri*)l->content;
	while (p->y + t->height < m->size + 1)
	{
		p->x = 0;
		while (p->x + t->width < m->size + 1)
		{
			//printf("[%d,%d]\n", p->x, p->y);
			if (place_tetri(t, m, p))
			{
				print_map(m);
				ft_putstr("\n");
				if (try_to_fill(m, l->next))
					return (1);
				set_value(t, m, p, '.');
			}
			p->x++;
		}
		p->y++;
	}
	return (0);
}

int		count_elem(t_list *l)
{
	int		i;

	i = 0;
	while (l->next)
	{
		i++;
		l = l->next;
	}
	return (i);
}

t_map	*resolve(t_list *l)
{
	int		size = get_mini_map_size(count_elem(l));
	t_map	*m = new_map(size);
	printf("resolving.....\n");
	while (!try_to_fill(m, l))
	{
		print_map(m);
	//	getchar();
		free(m);
		m = new_map(size++);
	}
	return (m);
}
