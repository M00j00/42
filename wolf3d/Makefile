# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amanchon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/28 23:00:04 by amanchon          #+#    #+#              #
#    Updated: 2016/11/06 22:35:11 by amanchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	wolf3d
FLAGS	=	-Wall -Wextra
LINK	=	-L./includes -lft -lmlx -framework OpenGL -framework AppKit
CC		=	gcc
SRC		=	main.c image.c texture.c raycaster.c hooks.c map.c get_next_line.c
OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):
	@$(MAKE) -C libft && mv libft/libft.a ../includes \
						&& cp libft/libft.h ../includes
	@$(MAKE) -C minilibx && mv minilibx/libmlx.a ../includes \
						&& cp minilibx/mlx.h ../includes
	$(CC) $(FLAGS) $(LINK) $(SRC) -o $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $^ -o $@

clean: 
	@$(MAKE) clean -C libft
	@$(MAKE) clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) fclean -C libft && rm -f /libft/libft.a
	@$(MAKE) fclean -C libft && rm -f /minilibx/mlx.a
	@rm -f $(NAME)

re: fclean all
