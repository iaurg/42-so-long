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

static int is_valid_wall(char **game_map)
{
	int i;
	int total_lines;

	i = 0;
	total_lines = -1;
	while(game_map[i])
	{
		// printf("test: %s\n", game_map[i]);
		total_lines++;
		i++;
	}

	i = 0;
	while (game_map[0][i])
		if (game_map[0][i++] != '1')
			return (print_error("Invalid line"));
	i = 0;
	while (game_map[total_lines][i])
		if (game_map[total_lines][i++] != '1')
			return (print_error("Invalid line"));
	return (print_error("Invalid map walls"));
}

int	validate_map(t_game game)
{
	if(!is_valid_wall(game.map))
		return (0); // 1 if is a valid map file
	return (1);
}
