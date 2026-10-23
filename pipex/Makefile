NAME = pipex
SRC = px_main.c px_close.c px_search.c
OBJ = ${SRC:.c=.o}
CC = gcc

BONUS = pipex_bonus
DIR_BONUS = ./bonus/
SRC_BONUS = px_main_bonus.c px_close_bonus.c px_search_bonus.c px_family_bonus.c px_heredoc_bonus.c
OBJ_BONUS = ${addprefix ${DIR_BONUS}, ${SRC_BONUS:.c=.o}}

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3 
MAKEFLAGS = --no-print-directory
LFLAGS = -L libft -lft

RM = rm -f

all: ${NAME}

${NAME}: ${OBJ}
	@cd libft && $(MAKE)
	@${CC} ${CFLAGS} ${OBJ} $(LFLAGS) -o ${NAME}

clean:
	@cd libft && $(MAKE) clean
	@echo "[🧹 Limpiando... 🧹]"
	@${RM} ${OBJ}
	@${RM} ${OBJ_BONUS}

fclean: clean
	@cd libft && $(MAKE) fclean
	@echo "    [🗑️ Mucho 🗑️ ]"
	@${RM} ${NAME}
	@${RM} ${BONUS}

re: fclean all
	@echo "[🛠️  Rehaciendo...🛠️ ]"

bonus: ${BONUS}

${BONUS}: $(OBJ_BONUS)
	cd libft && $(MAKE)
	${CC} ${CFLAGS} ${OBJ_BONUS} $(LFLAGS) -o ${BONUS}

rebonus: fclean bonus
	@echo "[🛠️  Rehaciendo...🛠️ ]"

.PHONY: all clean fclean re bonus rebonus