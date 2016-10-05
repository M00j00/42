/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 18:10:34 by amanchon          #+#    #+#             */
/*   Updated: 2016/04/04 17:46:44 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	del_tetri(t_tetri *t)
{
	int		i;

	if (!t)
		return ;
	i = 0;
	while (i < t->height)
	{
		ft_strdel(&t->buffer[i]);
		i++;
	}
	free(t->buffer);
	t->buffer = NULL;
	free(t);
	t = NULL;
}

void	free_list(t_list *l)
{
	t_list	*tmp;
	t_tetri	*t;

	while (l)
	{
		tmp = l->next;
		t = (t_tetri*)l->content;
		del_tetri(t);
		ft_memdel((void**)&l);
		l = tmp;
	}
}

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
		ft_memdel((void**)&p);
}
