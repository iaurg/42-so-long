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

- Your program must take as a first argument a map description file with the .ber
extension.

- The map must be closed/surrounded by walls, if not the program must return
an error.

- Map must have at least one exit, one collectible, and one starting position.

- You don’t need to check if there’s a valid path in the map.

- The map must be rectangular

- You must be able to parse any kind of map, as long as it respects the rules of
the map

- If any misconfiguration of any kind is encountered in the file, the program
must exit properly and return "Error\n" followed by an explicit error message
of your choice.
*/
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// Get map as a first argument and validate .ber extension
/* 
The map must be closed/surrounded by walls, if not the program must return
an error.

If any misconfiguration of any kind is encountered in the file, the program
must exit properly and return "Error\n" followed by an explicit error message
of your choice.
*/
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

// gcc -Wall -Wextra -Werror -I mlx -L mlx -lmlx -framework OpenGL -framework AppKit ./src/main.c
