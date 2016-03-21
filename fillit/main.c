/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:34:57 by amanchon          #+#    #+#             */
/*   Updated: 2016/03/16 16:37:27 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

char	*split_args(char *s)
{
	char		*tmp;
	char		*ret;

	if (!(ret = ft_strdup(s)))
		return (NULL);
	tmp = ret;
	while (*tmp != '\0')
	{
		if (*tmp == '\n' && *(tmp + 1) == '\n')
		{
			*(tmp + 1) = '\t';
		}
		tmp++;
	}
	return (ret);
}
char	*read_tetri(char *filename)
{
	int		rbytes;
	char	*str;
	char	*buff;
	int		fd;
	char	*tmp;

	str = ft_strnew(1);
	if (!(buff = (char*)malloc(sizeof(char) * 8)))
		return (NULL);
	fd = open(filename, O_RDONLY);
	while ((rbytes = read(fd, buff, 8)) > 0)
	{
		buff[rbytes] = '\0';
		tmp = str;
		str = ft_strjoin(str, buff);
		ft_strdel(&tmp);
	}
	ft_strdel(&buff);
	close(fd);
	return (str);
}

t_list	*reverse_list(t_list *l)
{
	t_list *start;
	t_list	*tmp;

	start = NULL;
	while (l)
	{
		tmp = l->next;
		l->next = start;
		start = l;
		l = tmp;
	}
	return (start);
}

int		main(int argc, char **argv)
{
	t_list		*tetri_list;
	char		*data;
	//t_map		*map = new_map(4);
	int			i,j;

	if (argc != 2)
	{
		ft_putendl_fd("usage: ./fillit sample_file\n", 2);
		return (1);
	}
	data = split_args(read_tetri(argv[1]));
	//printf("Tetriminons lu et split:\n%s\n--------------\n", data);
	if (!(tetri_list = reverse_list(create_list(data))))
	{
		ft_putendl_fd("error\n", 2);
		return (1);
	}
	print_list(tetri_list);
	/*i = 0;
	while (i < map->size - 1)
	{
		j = 0;
		while (j < map->size - 1)
		{
			place_tetri((t_tetri*)tetri_list->content, map, new_point(i,j));
			j++;
		}
		i++;
	}*/
	//place_tetri((t_tetri*)tetri_list->content, map, new_point(0,0));
	//print_map(map);
	//printf("--------------\n--------------------\n");
	
	print_map(resolve(tetri_list));
	return (0);
}
