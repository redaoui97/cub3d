# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/21 14:30:38 by rnabil            #+#    #+#              #
#    Updated: 2023/04/21 14:38:55 by rnabil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D
CC			= cc
FLAGS		= -Wall -Werror -Wextra -fsanitize=memory
LIBMLX		= -I ../minilibx-linux

GAME		= $(addprefix game_settings/, game_settings)
ERRORS		= $(addprefix errors/, error)
UTILS		= $(addprefix utils/, utils1)
PARSING		= $(addprefix parsing/, parsing)
MAIN		= $(addprefix src/, cub3d $(ERRORS) $(UTILS) $(PARSING) $(GAME)) 

SRC			= $(MAIN:=.c)
OBJ			= $(MAIN:=.o)
HEADER		= includes/cub3d.h
CUB3DHEADER = -Iincludes 


.PHONY: all clean fclean re bonus norm

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(OBJ) $(FLAGS) -g -I/usr/include -L../mlx_linux -L/usr/lib -I../mlx_linux ../mlx_linux/libmlx.a -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CUB3DHEADER) $(FLAGS) -g -I/usr/include -I../mlx_linux -O3 -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
