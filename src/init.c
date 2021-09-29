/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 22:46:20 by itaureli          #+#    #+#             */
/*   Updated: 2021/09/28 21:42:37 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

/*
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

- You must be able to parse any kind of map, as long as it respects the rules of
the map
*/

/*
[x] Map components
[x] Validate map extension .ber
[x] Validate map walls
[x] Validate retangular map
[x] Validate map elements
[x] You don’t need to check if there’s a valid path in the map.
[x] Validate Map must have at least one exit, one collectible, and one starting position.
[x] Init window with right size
[] Print sprites on screen
[] Close window when click on "X"
[x] Close window when hit ESC
*/

int	main(int argc, char **argv)
{
	t_game game;

	setbuf(stdout, NULL);
	if (argc != 2)
		return (print_error("Invalid number of arguments"));
	if (!is_valid_extension(argv[1]))
		return (0);
	game.map.map_array = generate_map_array(argv[1]);
	if (!validate_map(&game))
		return (0);
	window_init(&game);
	img_init(&game);
	key_hooks(&game);
	mlx_loop(game.mlx);
	return(0);
}
