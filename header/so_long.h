/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 09:01:50 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/02 09:01:53 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libs/mlx/mlx.h"
# include "../libs/libft/libft.h"
# define PLAYER_CHAR 'P'
# define WALL_CHAR '1'
# define FREE_CHAR '0'
# define COIN_CHAR 'C'
# define EXIT_CHAR 'E'
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define SPRITE_SIZE 32
# define PLAYER_IMG "assets/sprites/P.xpm"
# define WALL_IMG "assets/sprites/1.xpm"
# define FREE_IMG "assets/sprites/0.xpm"
# define COIN_IMG "assets/sprites/C.xpm"
# define EXIT_IMG "assets/sprites/E.xpm"
# define EXIT2_IMG "assets/sprites/E2.xpm"
# define EVENT_KEY_PRESS	2
# define EVENT_X_WIN_PRESS	17

typedef struct s_player
{
	int		x;
	int		y;
	int		count_steps;
	int		count_coins;
}				t_player;

typedef struct s_map
{
	char	**map_array;
	int		row;
	int		col;
	int		player_char;
	int		coin_char;
	int		exit_char;
	int		exit_x;
	int		exit_y;
}				t_map;

typedef struct s_images
{
	void	*img_coin;
	void	*img_wall;
	void	*img_player;
	void	*img_free;
	void	*img_exit;
	void	*img_exit2;
}				t_images;

typedef struct s_game
{
	t_map		map;
	void		*mlx;
	void		*screen;
	int			finished;
	t_images	img;
	t_player	player;
}				t_game;

int		print_error(char *message);
int		validate_map(t_game *game);
int		is_valid_extension(char *map_file);
char	**generate_map_array(char *map_file);
void	window_init(t_game *game);
void	map_init(t_game *game);
int		key_hooks(t_game *game);
void	move_elements(int keycode, t_game *game);
void	img_init(t_game *game);
int		close_game(t_game *game);
void	render_images(t_game *game);
int		map_and_validate_elements(t_game *game);
void	count_elements(t_game *game, char element);
#endif
