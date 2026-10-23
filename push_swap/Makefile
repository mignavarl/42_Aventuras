NAME = push_swap
SRC =ps_push_swap.c ps_check_number.c ps_atoi.c ps_create_bunker.c ps_free_things.c\
		ps_create_list.c ps_operations_swap.c ps_operations_push.c\
		ps_operations_rotate.c ps_sort_numbers.c ps_sort_trhee_numbers.c ps_index_list.c\
		ps_sort_few_numbers.c ps_sort_more_numbers.c
		

OBJ = ${SRC:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
MAKEFLAGS = --no-print-directory

LFLAGS = -L libft -lft

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@echo "[📝 Pushuapeando... 📝]"
	@cd libft && $(MAKE)
	@$(CC) $(OBJ) $(LFLAGS) -o $(NAME)

clean:
	@cd libft && $(MAKE) clean
	@$(RM) $(OBJ)

fclean: clean
	@cd libft && $(MAKE) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT: