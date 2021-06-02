# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile2                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adandres <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/27 02:42:08 by adandres          #+#    #+#              #
#    Updated: 2018/09/08 14:47:43 by adandres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = fdf
INCLUDES = -I /usr/local/include
LIBS = libft/libft.a -L /usr/X11/lib/ -lmlx -framework OpenGL \
	   -framework AppKit
SRC = src
SRC_FILES = $(wildcard $(SRC)/*.c)
OBJ_DIR = obj
OBJ_FILES = $(patsubst $(SRC)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

all : $(NAME)


$(NAME) : $(OBJ_FILES)
	cd libft && make
	$(CC) -o $(NAME) $(OBJ_FILES) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean :
	rm -f $(OBJ_FILES)
	cd libft && make clean

fclean : clean
	rm -f $(NAME)
	cd libft && make fclean

re : fclean all
	cd libft && make re	