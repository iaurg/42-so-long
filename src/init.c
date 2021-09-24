#include "../header/so_long.h"

/*
- Map components:
walls = 1
collectibles = C
free space = 0
exit map = E
player start position = P

- At every move the current number of movements must be displayed in the shell.

- The player must be able to move: move_up(), move_down(), move_left(), move_right()

- The game doesn’t need to be real-time.

- player cannot move into walls.

- The program displays the image in a window and respects the following rules:
◦ The W, A, S, and D keys will be used to move the main character.
◦ Pressing ESC must close the window and quit the program cleanly.
◦ Clicking on the red cross on the window’s frame must close the window and
quit the program cleanly.
◦ The use of images of the minilibX is strongly recommended.

- You don’t need to check if there’s a valid path in the map.

- You must be able to parse any kind of map, as long as it respects the rules of
the map
*/

// Get map as a first argument and validate .ber extension

int	main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		return (print_error("Invalid number of arguments"));
	if (!is_valid_extension(argv[1]))
		return (0);
	game.map.map_array = generate_map_array(argv[1]);

	if (!validate_map(&game))
		return (0);
	// If mlx_init fails to set up the connection to the graphical system, it will return NULL, otherwise a non-null pointer is returned as a connection identifier.
	// mlx = mlx_init();
	// To calculate screen size get number of rows and columns x tiles size
	//mlx_win = mlx_new_window(mlx, 300, 300, "so_long");

	// mlx_put_image_to_window(mlx, mlx_win, img.img, 50, 50);
	//mlx_loop(mlx);
	return(0);
}

// gcc -Wall -Wextra -Werror -I mlx -L mlx -lmlx -framework OpenGL -framework AppKit ./src/main.c
