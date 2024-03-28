NAME = push_swap
SRC =ps_push_swap.c ps_check_number.c ps_atoi.c ps_create_bunker.c ps_print_errors.c\
		ps_create_list.c ps_free_things.c

OBJ = ${SRC:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = libft/libft.a
LFLAGS = -L libft -lft

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@cd libft && $(MAKE)
	@$(CC) $(OBJ) $(MLX_FLAGS) $(LFLAGS) -o $(NAME)

clean:
	@cd libft && Make clean
	@$(RM) $(OBJ)

fclean: clean
	@cd libft && Make fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 