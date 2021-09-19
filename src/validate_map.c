#include "../header/so_long.h"

/*
Validate map extension .ber
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

int	validate_map(char *map_file)
{
	if(!is_valid_extension(map_file))
		return (0); // 1 if is a valid map file
	return (1);
}
