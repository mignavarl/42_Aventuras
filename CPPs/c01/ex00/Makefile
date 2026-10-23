NAME = zombie
SRC = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
OBJ = ${SRC:.cpp=.o}
CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=leak
RM = rm -f

all: ${NAME}

${NAME}: ${OBJ}
	${CXX} ${CXXFLAGS} ${OBJ} -o ${NAME}

clean:
	@echo "[🧹 Limpiando... 🧹]"
	@${RM} ${OBJ}

fclean: clean
	@echo "    [🗑️ Mucho 🗑️ ]"
	@${RM} ${NAME}

re: fclean all
	@echo "[🛠️  Rehaciendo...🛠️ ]"

.PHONY: all clean fclean re