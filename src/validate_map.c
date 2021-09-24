#include "../header/so_long.h"

/*
Validate map extension .ber - OK
Validate map walls
Validate retangular map
Validate map elements

- The map must be rectangular
- Map must have at least one exit, one collectible, and one starting position.
- The map must be closed/surrounded by walls, if not the program must return
an error.
- Your program must take as a first argument a map description file with the .ber
extension.
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

static int is_valid_wall(t_game *game)
{
	int i;
	int total_row;
	int total_col;
	i = 0;
	total_row = game->map.row;
	total_col = game->map.col;

	while (game->map.map_array[0][i])
		if (game->map.map_array[0][i++] != '1')
			return (print_error("Invalid line"));
	i = 0;
	while (game->map.map_array[total_row - 1][i])
		if (game->map.map_array[total_row - 1][i++] != '1')
			return (print_error("Invalid line"));
	printf("row: %d\n", total_row);
	printf("col: %d\n", total_col);
	return (print_error("Invalid map walls"));
}

static int is_valid_rectangle(t_game *game)
{
	if ((game->map.row <= 0) || (game->map.col <= 0))
		return (print_error("Invalid map row or col"));
	return(1);
}

static void count_map_sides(t_game *game)
{
	int total_row;
	int total_col;
	total_row = -1;
	total_col = 0;

	while (game->map.map_array[++total_row]);
	while (game->map.map_array[0][++total_col]);
	game->map.row = total_row;
	game->map.col = total_col;
}

int	validate_map(t_game *game)
{
	count_map_sides(game);
	if(!is_valid_wall(game) || !is_valid_rectangle(game))
		return (0); // 1 if is a valid map file
	return (1);
}
