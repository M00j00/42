/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 17:10:14 by amanchon          #+#    #+#             */
/*   Updated: 2016/06/21 19:23:55 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h" 

t_opt	parseArgs(char **args)
{
	t_opt	opt;
	char	*strOpt;
	char	*tmp;

	strOpt =(char*)malloc(sizeof(char));
	while (*args)
	{
		if (**args == '.')
			;
		else if (**args == '-')
			strcat(strOpt, *args);
		else
		{
			opt.dir = *args;
		}
		args++;
	}
	getOptions(strOpt, &opt);
	printOpt(opt);
	return (opt);
}
void getOptions(char *strOpt, t_opt *opt)
{
	opt->l = strchr(strOpt, 'l')? 1 : 0;
	opt->a = strchr(strOpt, 'a')? 1 : 0;
	opt->r = strchr(strOpt, 'r')? 1 : 0;
	opt->R = strchr(strOpt, 'R')? 1 : 0;
	opt->t = strchr(strOpt, 't')? 1 : 0;
}

void printOpt(t_opt opt)
{
	printf("dir = %s\nl = %d\na = %d\nR = %d\nr = %d\nt = %d",
			opt.dir, opt.l, opt.a, opt.R, opt.r, opt.t);
}
