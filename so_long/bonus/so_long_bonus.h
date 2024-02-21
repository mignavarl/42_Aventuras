/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:58:54 by mignavar          #+#    #+#             */
/*   Updated: 2024/02/21 14:49:04 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "../libft/libft.h"
# include "mlx.h"

typedef struct s_img
{
	void	*pj;
	void	*floor;
	void	*wall;
	void	*wall_2;
	void	*exit;
	void	*col;
	void	*open;
	void	*enemy;
	void	*black;
	void	*yellow;
}				t_img;

typedef struct s_game
{
	//MLX
	void	*mlx;
	void	*win;

	//CORDS PLAYER
	int		x;
	int		y;

	//MAP
	char	**map;
	int		col;
	int		mov;
	t_img	sprite;
}				t_game;

//MAP
char	**create_map(char *path);
int		get_alto(char *path);
int		get_total_line(char **map);
int		fill_map(char **map, int total_line, int final_line);
void	fill_pj(char **map, int line, int pos);

//CHECK_OBJECTS
int		check_map(char **map);
int		check_objects(char **map, int total_line);
int		check_wall(char **map, int total_line);
int		check_pj(char **map, int total_line);
int		check_col(char **map, int total_line);
int		check_exit(char **map, int total_line);
int		check_letter(char **map, int total_line);

//GAME
int		init_game(t_game *data);
int		key_event(int keycode, t_game *data);
void	key_move(int key, t_game *data);
void	key_col(t_game *data);
void	key_exit(t_game *data);
int		cross_window(t_game *data);
void	enemy_kill(t_game *data);
int		number_movements(t_game *data, t_img *sprite);

//PLAYER
void	restore_player(t_game *data, t_img *sprite);
void	pos_player(t_game *data);
int		put_player(t_game *data, t_img *sprite);

//BACKGROUND
int		put_background(t_game *data, t_img *sprite);
int		put_walls(t_game *data, void *wall);
int		put_floor(t_game *data, t_img *sprite);
int		put_col(t_game *data, t_img *sprite);
int		put_enemy(t_game *data, t_img *sprite);
int		animate_sea(t_game *data);
int		col_yellow(t_game *data);

//OTHER FUNCIONS
int		ft_strlen_no_n(char *map);
int		error_arg(int ac, char **av);
void	print_map(char **map);
void	free_all(t_game *data);
void	print_errors(int error);

#endif