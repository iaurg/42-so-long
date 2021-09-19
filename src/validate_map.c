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

int	validate_map(char *map_file)
{
	printf("%s", map_file);
	ft_putchar_fd('x', 1);
	return(1); // 1 if is a valid map file
}
