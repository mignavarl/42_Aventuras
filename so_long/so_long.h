/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:58:54 by mignavar          #+#    #+#             */
/*   Updated: 2024/02/14 15:35:41 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./libft/libft.h"
# include "mlx.h"

typedef struct s_img
{
	void	*pj;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*col;
}				t_img;

typedef struct s_game
{
	//MLX
	void	*mlx;
	void	*win;

	//CORDS
	int		x;
	int		y;

	char	**map;
	t_img 	sprite;
}				t_game;

//MAP
char    **create_map(char *path);
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
void	init_game(t_game *data);
int		key_event(int keycode, t_game *data);

//PLAYER
void	restore_player(t_game *data, t_img *sprite);
void	put_player(t_game *data, t_img *sprite);
void	pos_player(t_game *data);

//BACKGROUND
void	put_background(t_game *data, t_img *sprite);
void	put_walls(t_game *data, t_img *sprite);
void	put_floor(t_game *data, t_img *sprite);
void	put_col(t_game *data, t_img *sprite);

//OTHER FUNCIONS
int		ft_strlen_no_n(char *map);
int		error_arg(int ac, char **av);
void	print_map(char **map);

#endif