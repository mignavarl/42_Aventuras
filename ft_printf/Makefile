NAME = libftprintf.a
SRC = ft_printf.c ft_printf_basic.c ft_printf_hexa.c ft_printf_utils.c
OBJ = ft_printf.o ft_printf_basic.o ft_printf_hexa.o ft_printf_utils.o
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "[🛠️ Creando libreria... 🛠️ ]"
	@$(CC) -c $(CFLAGS) $(SRC)
	@ar -rsc $(NAME) $(OBJ)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re