NAME = push_swap
SRC =ps_push_swap.c ps_check_number.c ps_atoi.c ps_create_bunker.c ps_print_errors.c\
		ps_create_list.c ps_free_things.c ps_operations_swap.c ps_operations_push.c\
		ps_operations_rotate.c ps_orden_numbers.c ps_orden_trhee_numbers.c ps_index_list.c\
		ps_calculate_mov.c
		

OBJ = ${SRC:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

LFLAGS = -L libft -lft

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@echo "[📝 Pushuapeando... 📝]"
	@cd libft && $(MAKE)
	@$(CC) $(OBJ) $(LFLAGS) -o $(NAME)

clean:
	@cd libft && Make clean
	@$(RM) $(OBJ)

fclean: clean
	@cd libft && Make fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT: