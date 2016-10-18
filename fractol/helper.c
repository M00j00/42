/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 18:09:16 by amanchon          #+#    #+#             */
/*   Updated: 2016/10/18 18:37:37 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_line_data		*new_line_data(t_env *e, int x, int y, int x2, int y2)
{
	t_line_data *l;

	if (!(l = (t_line_data*)malloc(sizeof(t_line_data))))
		return (NULL);
	l->dx = ft_abs(x2 - x);
	l->dy = ft_abs(y2 -y);
	l->ix = (x < x2) ? 1 : -1;
	l->iy = (y < y2) ? 1 : -1;
	l->err = (l->dx > l->dy) ? l->dx /2 : -l->dy /2;
	return (l);
}
