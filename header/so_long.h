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

typedef struct	s_map
{
	char	**map_array;
	int		row;
	int		col;
}				t_map;

typedef struct	s_images
{
	void	*img_coin;
	void	*img_wall;
	void	*img_player;
	void	*img_free;
	void	*img_exit;
}				t_images;

typedef struct	s_game
{
	t_map	map;
	void	*mlx;
	void	*screen;
	t_images	img;
}				t_game;

int		print_error(char *message);
int		validate_map(t_game *game);
int		is_valid_extension(char *map_file);
char	**generate_map_array(char *map_file);
void	window_init(t_game *game);
int		key_hooks(t_game *game);
void	img_init(t_game *game);
#endif
