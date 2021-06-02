# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                        /       \.'`  `',.--//    #
#                                                     +:+ +:+         +:+      #
#    By: adandres <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/27 02:42:08 by adandres          #+#    #+#              #
#    Updated: 2021/06/02 14:30:44 by adandres                                  #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = fdf
INCLUDES = -I minilibx_macos
LIBS = libft/libft.a -framework OpenGL -framework AppKit
SRC = src
SRC_FILES = $(wildcard $(SRC)/*.c)
OBJ_DIR = obj
OBJ_FILES = $(patsubst $(SRC)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

all : $(NAME)


$(NAME) : $(OBJ_FILES)
	@make -C libft
	@make -C minilibx_macos
	$(CC) -o $(NAME) $(OBJ_FILES) $(LIBS) minilibx_macos/libmlx.a

$(OBJ_DIR)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean :
	rm -f $(OBJ_FILES)
	@make -C libft clean
	@make -C minilibx_macos clean

fclean : clean
	rm -f $(NAME)
	@make -C libft clean
	@make -C minilibx_macos clean

re : fclean all
