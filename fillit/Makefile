# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amanchon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/27 16:29:55 by amanchon          #+#    #+#              #
#    Updated: 2016/03/22 18:37:04 by amanchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit
FLAGS	=	-Wall -Wextra
CC		=	gcc
SRC		=	free.c main.c map.c resolver.c tetri.c verif.c

all:		$(NAME)

$(NAME):
	cd libft/ && $(MAKE)
	$(CC) $(FLAGS) $(SRC) -L ./libft -lft -o $(NAME)
	cd libft/ && $(MAKE) fclean

clean: 
	rm -f

fclean: clean
	rm -f $(NAME)

re: fclean all
