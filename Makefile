# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/21 14:30:38 by rnabil            #+#    #+#              #
#    Updated: 2023/05/17 16:10:49 by rnabil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D
	
CC			= cc
FLAGS		= -Wall -Wextra -Werror -fsanitze=address
RM			= rm -rf

INCLUDES	= -I /usr/local/include
LIBMLX		= -L /usr/local/lib

OBJDIR = .objFiles
OBJ            = $(MAIN:=.o)
SRC            = $(MAIN:=.c)
OBJ            = $(MAIN:=.o)
HEADER        = includes/cub3d.h
CUB3DHEADER = -Iincludes

EXECUTION	= $(addprefix execution/, execution dda hooks hooks_functions)
GAME		= $(addprefix game_settings/, game_settings)
ERRORS		= $(addprefix errors/, error)
UTILS		= $(addprefix utils/, utils1)
PARSING		= $(addprefix parsing/, parsing)
FILES		= $(addprefix src/, cub3d $(ERRORS) $(UTILS) $(PARSING) $(GAME) $(EXECUTION)) 

SRC			= $(FILES:=.c)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER		= $(addprefix includes/, cub3d.h)
CUB3DHEADER = -I includes

.PHONY: all clean fclean re bonus norm

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(OBJ) $(INCLUDES) $(CUB3DHEADER) $(LIBMLX) $(OPTS) -g -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJDIR)/%.o: %.c $(HEADER)
	mkdir -p $(dir $@)
	$(CC) -Wall -Wextra -Werror $(OPTS) $(CUB3DHEADER) $(OPTS) -g -c $< -o $@

NAME		= cub3D
CC			= cc
FLAGS		= -Wall -Werror -Wextra -fsanitize=address
LIBMLX		= -I ../minilibx-linux

clean:
	$(RM) $(OBJDIR) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all