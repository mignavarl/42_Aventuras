NAME = abstract
SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJ = ${SRC:.cpp=.o}
CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=leak -g3
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