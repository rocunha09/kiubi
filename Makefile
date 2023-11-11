#/* ************************************************************************** */
#/*                                                                            */
#/*                                                        :::      ::::::::   */
#/*   Makefile                                           :+:      :+:    :+:   */
#/*                                                    +:+ +:+         +:+     */
#/*   By: rafade-o <rafade-o@student.42.rio>        +#+  +:+       +#+         */
#/*                                                +#+#+#+#+#+   +#+           */
#/*   Created: 2023/10/04 18:13:10 by rafade-o          #+#    #+#             */
#/*   Updated: 2023/11/02 02:51:01 by rafade-o         ###   ########.fr       */
#/*                                                                            */
#/* ************************************************************************** */

SRCS =	./src/main.c 								\
		./src/functionalities/error.c				\
		./src/functionalities/color.c 				\
		./src/functionalities/minimap.c				\
		./src/functionalities/raycast.c				\
		./src/functionalities/render.c 				\
		./src/functionalities/utils.c				\
		./src/functionalities/utils2.c				\
		./src/functionalities/my_mlx.c 				\
		./src/functionalities/game.c 				\
		./src/functionalities/textures.c  			\
		./src/functionalities/player.c				\
		./src/functionalities/end_linux.c 			\
		./src/validation/check_closed_map.c 		\
		./src/validation/get_map.c 					\
		./src/validation/utils_map.c 				\
		./src/validation/validation_textures.c 		\
		./src/validation/general_utils.c 			\
		./src/validation/keys.c 					\
		./src/validation/utils_mlx.c				\
		./src/validation/get_colors.c 				\
		./src/validation/read_file.c 				\
		./src/validation/validation_file_utils.c	\
		./src/validation/get_coordinates.c 			\
		./src/validation/utils_cube.c 				\
		./src/validation/validation_map_utils.c		\
		./src/validation_adapter/ceiling_color.c 	\
		./src/validation_adapter/floor_color.c 		\
		./src/validation_adapter/ceiling_color_rgb.c 	\
		./src/validation_adapter/floor_color_rgb.c 		\
		./src/validation_adapter/file_descriptor.c 	\
		./src/validation_adapter/map.c				\
		./src/validation_adapter/rows_map.c			\
		./src/validation_adapter/cols_map.c			\
		./src/validation_adapter/player_direction.c	\
		./src/validation_adapter/map_n.c 			\
		./src/validation_adapter/map_e.c 			\
		./src/validation_adapter/map_s.c 			\
		./src/validation_adapter/map_w.c 			\


OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS =  -Wall -Wextra  -Wno-unused-function #-Werror 

LIBFT_DIR = ./vendor/libft
GNL_DIR = ./vendor/get_next_line
MINILIBX_DIR = ./vendor/miniLibX

LIBFT = $(LIBFT_DIR)/libft.a
GNL = $(GNL_DIR)/libgnl.a
MINILIBX = $(MINILIBX_DIR)/libmlx.a

INCLUDE = -I include -I $(LIBFT_DIR) -I $(GNL_DIR) -I $(MINILIBX_DIR)

NAME = cub3d

all: libft gnl mlx $(NAME)
	@echo "Compilando tudão..."

libft:
	@echo "Compilando a libft"
	@$(MAKE) -C $(LIBFT_DIR)

gnl:
	@echo "Compilando a gnl"
	@$(MAKE) -C $(GNL_DIR)

mlx:
	@echo "Compilando a minilibx"
	@$(MAKE) -C $(MINILIBX_DIR)

$(NAME): $(OBJS)
	@echo "Compilando o programa principal..."
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft -L$(GNL_DIR) -lgnl -L$(MINILIBX_DIR) -lmlx -lm -lX11 -lXext 

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS)

clean-libft:
	@$(MAKE) -C $(LIBFT_DIR) clean

clean-gnl:
	@$(MAKE) -C $(GNL_DIR) clean

clean-mlx:
	@$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean fclean-libft fclean-gnl fclean-mlx
	rm -f $(NAME)

fclean-libft:
	@$(MAKE) -C $(LIBFT_DIR) fclean

fclean-gnl:
	@$(MAKE) -C $(GNL_DIR) fclean

fclean-mlx:
	@$(MAKE) -C $(MINILIBX_DIR) clean

re: fclean fclean-libft fclean-gnl fclean-mlx all

.PHONY: all libft gnl mlx clean clean-libft clean-gnl clean-mlx fclean fclean-libft fclean-gnl fclean-mlx re
