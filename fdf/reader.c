/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 01:48:32 by amanchon          #+#    #+#             */
/*   Updated: 2016/11/17 04:52:21 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map		*new_map(int h, int w)
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

static void			extract_nbr(char *str, int *arr)
{
	int		w;
	char	**data;

	w = 0;
	data = ft_strsplit(str, ' ');
	while (data[w] != NULL)
	{
		arr[w] = ft_atoi(data[w]);
		ft_strdel(&data[w]);
		w++;
	}
	free(data);
	w = 0;
	return ;
}

static void			get_map_dim(int fd, int *height, int *width)
{
	char	*line;
	int		current_w;
	int		i;

	while (get_next_line(fd, &line) > 0)
	{
		*height += 1;
		current_w = 0;
		i = 0;
		while (line[i] != '\0')
		{
			if (ft_isdigit(line[i]))
			{
				while (line[i] != '\0' && !ft_isspace(line[i]))
					i++;
				current_w += 1;
			}
			else
				i++;
		}
		*width = current_w > *width ? current_w : *width;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd);
}

t_map				*get_map_data(char *filename)
{
	int		fd;
	char	*line;
	int		h;
	int		w;
	t_map	*m;

	h = 0;
	w = 0;
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
	{
		extract_nbr(line, m->data[h++]);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (m);
}
