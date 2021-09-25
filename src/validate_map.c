#include "../header/so_long.h"

/*
Validate map extension .ber - OK
Validate map walls - OK
Validate retangular map - OK
Validate map elements - OK
Validate Map must have at least one exit, one collectible, and one starting position.
*/

int is_valid_extension(char *map_file)
{
	char *ext;

	if(!map_file)
		return (0);
	ext = ft_strrchr(map_file, '.');
	if (ft_strncmp(ext, ".ber", 5) == 0)
		return (1);
	print_error("Invalid map extension");
	return(0);
}

static int	is_valid_wall(t_game *game)
{
	int	i;
	int	row;
	int	col;
	int	lst_line;

	i = 0;
	row = game->map.row;
	col = game->map.col;
	lst_line = row - 1;
	while (game->map.map_array[0][i] && game->map.map_array[lst_line][i])
	{
		if (game->map.map_array[0][i] != '1')
			return (print_error("Invalid wall"));
		if (game->map.map_array[lst_line][i] != '1')
			return (print_error("Invalid wall"));
		i++;
	}
	i = 0;
	while (i <= lst_line)
	{
		if (game->map.map_array[i][col - 1] != '1' ||
			game->map.map_array[i][0] != '1')
			return (print_error("Invalid line"));
		i++;
	}
	return (1);
}

static int is_valid_rectangle(t_game *game)
{
	if ((game->map.row < 5) || (game->map.col < 3))
		return (print_error("Invalid map row or col"));
	return(1);
}

static int	is_valid_elements(t_game *game)
{
	int	i;
	int	j;
	int	row;
	int	col;
	char element;

	i = 0;
	j = 0;
	row = game->map.row;
	col = game->map.col;

	while(i < row)
	{
		while(j < col)
		{
			element = game->map.map_array[i][j];
			if (element != PLAYER_CHAR
				&& element != COIN_CHAR
				&& element != WALL_CHAR
				&& element != FREE_CHAR
				&& element != EXIT_CHAR)
				return(print_error("Invalid element in map"));
			j++;
		}
		j = 0;
		i++;
	}

	return(1);
}

static void count_map_sides(t_game *game)
{
	int total_row;
	int total_col;
	total_row = 0;
	total_col = 0;

	while (game->map.map_array[++total_row]);
	while (game->map.map_array[0][++total_col]);
	game->map.row = total_row;
	game->map.col = total_col;
}

int	validate_map(t_game *game)
{
	count_map_sides(game);
	if(!is_valid_wall(game)
		|| !is_valid_elements(game)
		|| !is_valid_rectangle(game))
		return (0); // 1 if is a valid map file
	return (1);
}
