NAME = so_long

SOURCES  = get_next_line.c get_next_line_utils.c read.c so_long.c parsing.c libft.c check_name.c player_pass.c free.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc
# CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.c so_long.h map.ber
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	@rm -rf $(OBJECTS) $(BOBJECTS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all 