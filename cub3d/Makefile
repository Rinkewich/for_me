# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpirzad <bpirzad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/06 23:39:26 by bpirzad           #+#    #+#              #
#    Updated: 2022/11/06 23:39:32 by bpirzad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	cub3d

FLAGS	= 	-Wall -Werror -Wextra -g -fsanitize=address

SRC		= 	\
            src/parce/identifiers/ident_parse.c \
            src/parce/identifiers/resolution.c \
            src/parce/identifiers/texture.c \
            src/parce/identifiers/ident_print.c \
            src/parce/map/map.c \
            src/parce/map/symbol_check.c \
            src/parce/map/tmp_map.c \
            src/parce/map/player.c \
            src/parce/map/doors_init.c \
            src/parce/file_parse.c \
            src/parce/valid_input.c \
            src/screen/raycasting.c \
            src/screen/screen.c \
            src/screen/texturisation.c \
            src/screen/mini_map.c \
            src/screen/floor_cell.c \
            src/screen/sort_sprite.c\
            src/screen/draw_sprite.c \
            src/screen/ray_walls.c \
            src/utils/move.c \
            src/utils/turn.c \
            src/utils/err_exit.c \
            src/utils/init_struct.c \
            src/utils/bmp.c \
	        src/utils/manage.c \
            cub3d.c

OBJ		= 	$(SRC:.c=.o)

INC		= -I ./include -I ./libft -I ./mlx

LIBFT	=	-L ./libft -lft

MLX		=	-L ./mlx -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

lft:
	make -C ./libft
	make -C ./mlx

$(NAME): $(OBJ) lft
	gcc $(FLAGS) $(INC) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

clean:
	/bin/rm -rf $(OBJ)
	make -C ./libft/ clean
	make -C ./mlx/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./libft/ fclean

re: fclean all