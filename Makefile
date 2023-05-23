# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazzouzi <mazzouzi@student.42.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/21 14:30:38 by rnabil            #+#    #+#              #
#    Updated: 2023/05/23 10:35:44 by mazzouzi         ###   ########.fr        #
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
TEXTURES	= $(addprefix textures/, textures_init textures_rendering)
GAME		= $(addprefix game_settings/, game_settings)
ERRORS		= $(addprefix errors/, error)
PARSING		= $(addprefix parsing/, parsing parsing_map_check parsing_map parsing_utils)
UTILS		= $(addprefix utils/get_next_line/, get_next_line get_next_line_utils)
LIBFT		= $(addprefix utils/libft/, ft_isalpha ft_isdigit ft_isalnum ft_isascii \
			ft_isprint ft_strlen ft_memset ft_bzero ft_memcpy \
			ft_memmove ft_strlcpy ft_strlcat ft_toupper ft_tolower \
			ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp \
			ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin \
			ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri \
			ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd)
FILES		= $(addprefix src/, cub3d $(TEXTURES) $(ERRORS) $(UTILS) $(PARSING) $(GAME) $(EXECUTION) $(LIBFT)) 
SRC			= $(FILES:=.c)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER		= $(addprefix includes/, cub3d.h get_next_line.h)
CUB3DHEADER = -I includes

.PHONY: all clean fclean re bonus norm

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(OBJ) $(INCLUDES) $(CUB3DHEADER) $(LIBMLX) $(OPTS) -g -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJDIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
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