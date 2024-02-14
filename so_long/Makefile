NAME = so_long
SRC =so_long.c sl_check_objects.c sl_other_funcions.c sl_map_utils.c sl_fill_map.c sl_print_error.c\
	sl_window_game.c sl_player.c sl_background.c sl_items_map.c 

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -c

LIBFT_DIR = libft/libft.a
LFLAGS = -L libft -lft

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@cd libft && $(MAKE)
	@$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit $(LFLAGS) -o $(NAME)

clean:
	@cd libft && Make clean
	@$(RM) $(OBJ)

fclean: clean
	@cd libft && Make fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re