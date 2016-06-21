/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 18:55:05 by amanchon          #+#    #+#             */
/*   Updated: 2016/06/21 19:33:26 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	listDir(const char *dname)
{
	DIR				*d;
	struct dirent	*entry;

	entry = NULL;
	if (!(d = opendir(dname)))
		return ;
	while ((entry = readdir(d)))
	{
		printf("%s\n", entry->d_name);
	}
}

void	listDirRec(const char *dname, int level)
{
	DIR		*d;
	struct	dirent *entry;
	struct stat		sent;
	char			*path;
	int file = 1;
	if (!(d = opendir(dname)))
		return ;
	if (!(entry = readdir(d)))
		return ;
	while ((entry = readdir(d)))
	{
	//	printf("lest go");
		path = getPath(dname, entry->d_name);
		//printf("<%s>", path);
		stat(path, &sent);
		if (S_ISDIR(sent.st_mode))
		{
			if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
				continue ;
			printf("%*s[%s]\n", level * 2, "", entry->d_name);
			listDirRec(path, level +1);
		}
		else
			printf("%*s - %s\n", level * 2, "", entry->d_name);
	}
	closedir(d);
}

char	*getPath(const char *dirname, char *filename)
{
	char	*path;
	char	lastc;

	path = strdup(dirname);
	lastc = path[strlen(path) - 1];
	//printf("[[[%c]]]", lastc);
	if (lastc != '/')
		path = strcat(path, "/");
	path = strcat(path, filename);
	printf("<<%s>>\n", path);
	//printf("building path 3/3 %s\n", path);
	return (path);
}
