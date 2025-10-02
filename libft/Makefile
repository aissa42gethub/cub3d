# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azrulsaleh <azrulsaleh@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 13:43:06 by azsaleh           #+#    #+#              #
#    Updated: 2025/08/31 22:48:02 by azrulsaleh       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# variables
NAME = libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror
INC_DIR = includes
SRC_DIR = sources
SRC_FILE = ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_printf.c \
		ft_printf_utils.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_freeswpptr.c \
		ft_atol.c \
		ft_freearray.c \
		ft_atoi_base.c \
		ft_ishex.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILE))
OBJ_DIR = objects
OBJ_FILE = $(SRC_FILE:.c=.o)
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ_FILE))
RM = rm -f -r
AR = ar rcs

#default rule
all: $(NAME)

#compile .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -I$(INC_DIR) -c $< -o $@

#create binary
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

#utility targets
clean:
	$(RM) $(OBJ_DIR)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY:	all clean fclean re