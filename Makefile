NAME		= cub3D
CC			= cc
FLAGS		= 
LIBMLX		= -I ../minilibx-linux

MAIN		= $(addprefix srcs/, cub3d)

SRC			= $(MAIN:=.c)
OBJ			= $(addprefix $(MAIN:=.o))
HEADER		= includes/cub3d.h
CUB3DHEADER = -Iincludes 


.PHONY: all clean fclean re bonus norm

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(OBJ) -I/usr/include -L../mlx_linux -L/usr/lib -I../mlx_linux ../mlx_linux/libmlx.a -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CUB3DHEADER) -I/usr/include -I../mlx_linux -O3 -c $< -o $@

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all
