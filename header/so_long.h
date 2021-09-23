#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libs/mlx/mlx.h"
# include "../libs/libft/libft.h"
# define PLAYER_CHAR = 'P'
# define WALL_CHAR = '1'
# define FREE_CHAR = '0'
# define COIN_CHAR = 'C'
# define EXIT_CHAR = 'E'

typedef struct	s_game
{
	char **map;
}				t_game;

int	print_error(char *message);
int	validate_map(t_game game);
int is_valid_extension(char *map_file);
char **generate_map_array(char *map_file);
#endif
