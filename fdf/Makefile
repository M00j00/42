# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amanchon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/05 07:20:04 by amanchon          #+#    #+#              #
#    Updated: 2016/11/18 04:19:05 by amanchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf
FLAGS	=	-Wall -Wextra -Werror
LIB		=	-L./includes -lft -lmlx -framework OpenGL -framework AppKit
CC		=	gcc
SRC		=	main.c draw.c point.c reader.c image.c event.c
OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):
	$(MAKE) -C libft
	mkdir includes
	cp libft/libft.a ./includes/
	cp libft/libft.h ./includes/
	cp /usr/local/lib/libmlx.a ./includes/
	cp /usr/local/include/mlx.h ./includes/
	$(CC) $(FLAGS) $(LIB) $(SRC) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $^ -o $@

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C libft fclean
	rm -rf ./includes/
	rm -f $(NAME)

re: fclean all
