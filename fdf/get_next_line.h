/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 18:10:39 by amanchon          #+#    #+#             */
/*   Updated: 2016/06/01 18:00:16 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"

# include <fcntl.h>

# define BUFF_SIZE 12
# define MAXFILE 2048

typedef struct			s_storage
{
	char	*memory[MAXFILE];
	int		nb_bytes;
	char	*buffer;
}						t_storage;

int						get_next_line(int fd, char **line);

#endif
