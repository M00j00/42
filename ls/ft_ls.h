/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 18:55:12 by amanchon          #+#    #+#             */
/*   Updated: 2016/06/21 19:12:02 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
//# include "libft/libft.h"
# include <stdlib.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct		s_opt
{
	char	*dir;
	int		l;
	int		R;
	int		a;
	int		r;
	int		t;
}					t_opt;

void	listDir(const char *dname);
void	listDirRec(const char *dname, int level);
char	*getPath(const char *dname, char *fname);
void	getOptions(char *strOpt, t_opt *opt);
t_opt	parseArgs(char **args);
void	printOpt(t_opt opt);
#endif
