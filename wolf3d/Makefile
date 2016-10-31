# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amanchon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/28 23:00:04 by amanchon          #+#    #+#              #
#    Updated: 2016/10/31 22:30:27 by amanchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	wolf3d
FLAGS	=	-Wall -Wextra
LIB		=	-L./includes -lft -lmlx -framework OpenGL -framework AppKit
CC		=	gcc
SRC		=	main.c image.c texture.c raycaster.c hooks.c
OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):
	cd libft/ && $(MAKE) && mv libft.a ../includes && cp libft.h ../includes
	cd minilibx/ && $(MAKE) && mv libmlx.a ../includes && cp mlx.h ../includes
	$(CC) $(FLAGS) $(LIB) $(SRC) -o $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $^ -o $@

clean: 
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
