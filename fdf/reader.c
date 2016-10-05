/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 01:48:32 by amanchon          #+#    #+#             */
/*   Updated: 2016/09/28 07:57:05 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map		*get_map_data(char *filename)
{
	int		fd;
	char	*line;
	int		h;
	int		w;
	t_map	*m;

	h = 0;
	w = 0;
	line = ft_strnew(1);
	if (!(ft_strstr(filename, ".fdf")))
		return (NULL);
	if ((fd = open(filename, O_RDONLY)) <= 0)
		return (NULL);
	get_map_dim(fd, &h, &w);
	if (!(m = new_map(h, w)))
		return (NULL);
	h = 0;
	if ((fd = open(filename, O_RDONLY)) <= 0)
		return (NULL);
	while (get_next_line(fd, &line) > 0)
		extract_nbr(line, m->data[h++]);
	return (m);
}

t_map		*new_map(int h, int w)
{
	t_map	*m;
	int		i;

	i = 0;
	if (!(m = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	if (!(m->data = (int**)malloc(sizeof(int*) * h)))
		return (NULL);
	while (i < h)
	{
		if (!(m->data[i++] = (int*)malloc(sizeof(int) * w)))
			return (NULL);
	}
	m->h = h;
	m->w = w;
	return (m);
}

void		extract_nbr(char *str, int *arr)
{
	int		w;
	char	**data;

	w = 0;
	data = ft_strsplit(str, ' ');
	while (*data != NULL)
		arr[w++] = ft_atoi(*data++);
	return ;
}

void		get_map_dim(int fd, int *height, int *width)
{
	char	*line;
	char	*temp;

	line = ft_strnew(1);
	while (get_next_line(fd, &line) > 0)
	{
		*height += 1;
		if (*line != '\0' && *height == 1)
		{
			temp = ft_strdup(line);
		}
	}
	while (*temp != '\0')
	{
		if (ft_isdigit(*temp))
		{
			while (*temp != '\0' && !ft_isspace(*temp))
				temp++;
			*width += 1;
		}
		else
			temp++;
	}
	close(fd);
}
