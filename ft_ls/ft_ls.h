/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 06:48:29 by amanchon          #+#    #+#             */
/*   Updated: 2016/11/18 09:28:05 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>

# define L 0
# define A 1
# define R 2
# define REC 3
# define T 4

typedef int				t_opt[5];
typedef struct stat		t_stat;
typedef struct dirent	t_dirent;

typedef struct			s_file_info
{
	char				*name;
	char				*path;
	t_stat				*stat;
	int					type;
}						t_file_info;

int		parse_args(char **args, t_opt *opt);

#endif
