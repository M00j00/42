
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 18:10:34 by amanchon          #+#    #+#             */
/*   Updated: 2016/03/16 15:52:17 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	del_tetri(void *content, size_t size)
{
	int		i;
	t_tetri	*t;

	i = 0;
	t = (t_tetri*)content;
	size = 0;
	while (i < t->height)
	{
		ft_strdel(&t->buffer[i]);
	}
	free(t->buffer);
	t->buffer = NULL;
	free(t);
	t = NULL;
}

void	free_list(t_list *l)
{
	void (*del)(void*, size_t);
	del = del_tetri;
	ft_lstdel(&l, *del);
}
/*
void	print_list(t_list *l)
{
	t_tetri		*t;

	while (l)
	{
		t = (t_tetri*) l->content;
		printf("----------------------------\n     addr : %p\ncontent :\n    lettre: %c\n    tetri:\n%s\n%s\n%s\n%s\n----------------------------\n     |     \n     |\n     |\n     V \n\n", l, t->letter, t->buffer[0], t->buffer[1], t->buffer[2], t->buffer[3]);
		l = l->next;
	}
	ft_putchar('\n');
}
*/
t_point	*new_point(int x, int y)
{
	t_point	*p;

	if (!(p = (t_point*)malloc(sizeof(t_point))))
		return (NULL);
	p->x = x;
	p->y = y;
	return (p);
}

void	free_point(t_point *p)
{
	if (p)
	{
		free(p);
		p = NULL;
	}
}
