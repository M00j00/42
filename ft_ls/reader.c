/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 08:54:57 by amanchon          #+#    #+#             */
/*   Updated: 2016/11/18 10:43:48 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"//https://github.com/st3w4r/42-ft_ls/blob/master/ft_ls.c

static t_file_info			*new_file_info(char *n, char *p, t_stat *s, int t)
{
	t_file_info	*ret;

	if (!(ret = (t_file_info*)malloc(sizeof(t_file_info))))
		return (NULL);
	ret->name = ft_strdup(n);
	ret->path = ft_strdup(p);
	ret->stat = s;
	ret->type = t;
	return (ret);
}

int					get_file_type(char *file)
{
	t_stat		*data;

	if (!(data = (t_stat*)malloc(sizeof(t_stat))))
		exit(1);
	if (stat(file, data) == -1)
		return (0);
	else if (S_ISDIR(data->st_mode))
		return (1);
	else if (S_ISREG(data->st_mode))
		return (2);
	return (0);
}

static int			add_dir(t_list *lst, char* name)
{
	DIR			*dir;
	t_dirent	*entity;
	t_stat		*st;

	if (!(dir = opendir(name)))
			return (0);
	while ((entity = readdir(dir)))
	{
		if (!(st = (t_stat*)malloc(sizeof(t_stat))))
			return(0);
		stat(entity->d_name, st);
		ft_lstadd(&lst, ft_lstnew(new_file_info(entity->d_name,
						name, st, 1), sizeof(t_file_info)));
	}
	return (1);
}

static int			add_file(t_list *lst, char *name)
{
	t_stat		*st;

	if (!(st = (t_stat*)malloc(sizeof(t_stat))))
		return(0);
	stat(name, st);
	ft_lstadd...
}

t_list				*get_dir_data(char *dirname)
{
	t_list		*lst;
	t_stat		*st;

	if (get_file_type(dirname) == 0)
		return (NULL);
	else if (get_file_type(dirname) == 1)
	{

	}
	else if (get_file_type(dirname) == 2)
	{
	
	}
	return (lst);
}
