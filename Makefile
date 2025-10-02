# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 15:54:12 by azsaleh           #+#    #+#              #
#    Updated: 2025/09/01 13:27:13 by azsaleh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
FLAG = -g
# FLAG = -Wall -Wextra -Werror -g
INC_DIR = includes
SRC_DIR = sources
SRCS = $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/*/*.c)
OBJ_DIR = objects
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
RM = rm -f -r
# LIB = -Llibft -lft -Lminilibx-macos -lmlx -framework OpenGL -framework AppKit
LIB = -Llibft -lft -Lminilibx-linux -lmlx_Linux -L/usr/lib -Iminilibx_linux -lXext -lX11 -lm -lz

#default rule
all: $(NAME)

#compile .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(FLAG) -I$(INC_DIR) -Ilibft/includes -Iminilibx-linux -c $< -o $@	
# $(CC) $(FLAG) -I$(INC_DIR) -Ilibft/includes -Iminilibx-macos -c $< -o $@

#create binary
$(NAME): $(OBJS)
	@make -C libft
	@make -C minilibx-linux
	$(CC) $(FLAG) $(OBJS) $(LIB) -o $(NAME)
# @make -C minilibx-macos

#utility targets
libft:
	make -C libft
minilibx:
	make -C minilibx
clean:
	make clean -C libft
	make clean -C minilibx-linux
	$(RM) $(OBJ_DIR)
# make clean -C minilibx-macos
fclean: clean
	make fclean -C libft
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re