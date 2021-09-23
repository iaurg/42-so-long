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

static int is_valid_extension(char *map_file)
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

static char **generate_map_array(char *map_file)
{
	int file_descriptor;
	char *temp;
	char *map_string;
	char *temp_map;

	file_descriptor = open(map_file, O_RDONLY);
	map_string = ft_strdup("");
	while (1)
	{
		temp = get_next_line(file_descriptor);
		temp_map = map_string;
		if (temp)
			map_string = ft_strjoin(temp_map, temp);
		free(temp);
		if (!temp) break;
	}
	return(ft_split(map_string, '\n'));
}

static int is_valid_wall(char *map_file)
{
	char **tst;
	int i;

	tst = generate_map_array(map_file);
	i = 0;
	while(tst[i])
	{
		printf("test: %s\n", tst[i]);
		i++;
	}

	return(print_error("Invalid map walls"));
}s

int	validate_map(char *map_file)
{
	if(!is_valid_extension(map_file))
		return (0); // 1 if is a valid map file
	if(!is_valid_wall(map_file))
		return (0); // 1 if is a valid map file
	return (1);
}
