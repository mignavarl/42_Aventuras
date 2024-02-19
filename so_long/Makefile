NAME = so_long
SRC =so_long.c sl_check_objects.c sl_other_funcions.c sl_map_utils.c sl_fill_map.c sl_print_error.c\
	sl_window_game.c sl_player.c sl_background.c sl_collectables_map.c 

OBJ = ${SRC:.c=.o}

BONUS = so_long_bonus

DIR_BONUS = ./bonus/

BONUS_SRC =so_long_bonus.c sl_check_objects_bonus.c sl_other_funcions_bonus.c sl_map_utils_bonus.c sl_fill_map_bonus.c sl_print_error_bonus.c\
	sl_window_game_bonus.c sl_player_bonus.c sl_background_bonus.c sl_collectables_map_bonus.c sl_enemy_bonus.c

BONUS_OBJ = ${addprefix ${DIR_BONUS}, ${BONUS_SRC:.c=.o}}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -c

LIBFT_DIR = libft/libft.a
LFLAGS = -L libft -lft
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@cd libft && $(MAKE)
	@$(CC) $(OBJ) $(MLX_FLAGS) $(LFLAGS) -g -o $(NAME)

bonus: ${BONUS}

$(BONUS): $(BONUS_OBJ)
	@cd libft && $(MAKE)
	@$(CC) $(BONUS_OBJ) $(MLX_FLAGS) $(LFLAGS) -g -o $(BONUS)

clean:
	@cd libft && Make clean
	@$(RM) $(OBJ)
	@$(RM) $(BONUS_OBJ)

fclean: clean
	@cd libft && Make fclean
	@$(RM) $(NAME)
	@$(RM) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus