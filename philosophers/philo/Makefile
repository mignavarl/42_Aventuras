NAME = philo
SRC = ph_main.c ph_stats.c ph_utils.c
OBJ = ${SRC:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -O0 -fsanitize=thread
RM = rm -rf

all: ${NAME}

${NAME}: ${OBJ}
	@${CC} ${CFLAGS} ${OBJ} -o ${NAME}

clean:
	@${RM} ${OBJ}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re