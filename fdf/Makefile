# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amanchon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/05 07:20:04 by amanchon          #+#    #+#              #
#    Updated: 2016/10/05 20:36:11 by amanchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf
FLAGS	=	-Wall -Wextra -O0 -g
LIB		=	-L./includes -lft -lmlx -framework OpenGL -framework AppKit
CC		=	gcc
SRC		=	main.c get_next_line.c get_map.c draw.c point.c reader.c image.c\
			event.c
OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):
	cd libft/ && $(MAKE) && mv libft.a ../includes && cp libft.h ../includes
	cd minilibx/ && $(MAKE) && mv libmlx.a ../includes && cp mlx.h ../includes
	$(CC) $(FLAGS) $(LIB) $(SRC) -o $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $^ -o $@

clean:
	@cd libft/ && $(MAKE) clean
	@cd minilibx/ && $(MAKE) clean
	@rm -f $(OBJ)

fclean: clean
	#@cd libft/ && $(MAKE) fclean
	#@cd minilibx/ && $(MAKE) fclean
	rm -f ../includes/libft.a
	rm -f ../includes/libmlx.a
	@rm -f $(NAME)

re: fclean all
