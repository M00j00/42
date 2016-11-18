/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 07:14:25 by amanchon          #+#    #+#             */
/*   Updated: 2016/11/18 08:49:22 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		check_valid(char c)
{
	return (c == 'l' || c == 'a' || c == 'r' || c == 'R' || c == 't');
}

int		parse_args(char **args, t_opt *opt)
{
	int			i;
	int			j;

	i = 1;
	while (args[i] && args[i][0] == '-')
	{
		j = 1;
		while (args[i][j])
		{
			if (!(check_valid(args[i][j])))
				exit(1);
			*opt[L] = args[i][j] == 'l' ? 1 : 0;
			*opt[A] = args[i][j] == 'a' ? 1 : 0;
			*opt[R] = args[i][j] == 'r' ? 1 : 0;
			*opt[REC] = args[i][j] == 'R' ? 1 : 0;
			*opt[T] = args[i][j] == 't' ? 1 : 0;
			j++;
		}
		i++;
	}
	return (i);
}
