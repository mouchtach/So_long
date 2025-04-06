NAME = so_long

SOURCES  = check/check_map.c \
			check/check_name.c \
			check/check_utils.c \
			check/check.c \
			read/get_next_line_utils.c \
			read/get_next_line.c \
			read/libft.c \
			read/read.c \
			game/load.c \
			game/game.c \
			game/move.c \
			game/derects.c \
			free.c  so_long.c \

# LDFLAGS = -L MLX42/build -L /Users/ymouchta/.brew/lib -lmlx42 -lglfw -framework OpenGL -framework AppKit -ldl -pthread -lm
LDFLAGS = -L MLX42/build -lmlx42 -lX11 -lXext -lm -pthread -lglfw -ldl

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LDFLAGS) -o $(NAME)

%.o: %.c so_long.h map.ber
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	@rm -rf $(OBJECTS) $(BOBJECTS)

fclean: clean
	@rm -rf $(NAME)

mlx:
	@git clone https://github.com/codam-coding-college/MLX42.git
build:
	@cmake MLX42 -B MLX42/build
	@make -C MLX42/build -j4

re: fclean all 