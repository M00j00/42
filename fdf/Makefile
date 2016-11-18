# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amanchon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/05 07:20:04 by amanchon          #+#    #+#              #
#    Updated: 2016/11/17 04:43:13 by amanchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf
FLAGS	=	-Wall -Wextra -Werror
LIB		=	-L./includes -lft -lmlx -framework OpenGL -framework AppKit
CC		=	gcc
SRC		=	main.c get_next_line.c get_map.c draw.c point.c reader.c image.c\
			event.c
OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):
	@$(MAKE) -C libft
	@cp libft/libft.a ./includes/ && cp libft/libft.h ./includes/
	@$(MAKE) -C minilibx
	@cp minilibx/libmlx.a ./includes/ && cp minilibx/mlx.h ./includes/
	$(CC) $(FLAGS) $(LIB) $(SRC) -o $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $^ -o $@

clean:
	@$(MAKE) -C libft clean
	@$(MAKE) -C minilibx clean
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C libft fclean
	@rm -f ./includes/libft.a
	@rm -f ./includes/libmlx.a
	@rm -f $(NAME)

re: fclean all
