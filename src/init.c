/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 22:46:20 by itaureli          #+#    #+#             */
/*   Updated: 2021/09/29 22:52:54 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

/*
[x] Map components
[x] Validate map extension .ber
[x] Validate map walls
[x] Validate retangular map
[x] Validate map elements
[x] You don’t need to check if there’s a valid path in the map.
[x] Validate Map must have at least one exit, one collectible, and one starting position.
[x] Init window with right size
[x] Print sprites on screen
[x] Close window when click on "X"
[x] Close window when hit ESC
[] Validate SIGSERV on game exit (quit the program cleanly.)
[] Check if all local functions are static
[] Validate norminette

Move
[] Move character (WASD)
[] The player must be able to move: move_up(), move_down(), move_left(), move_right()
[] Player cannot move into walls
[] Collect coins
[] Allow exit into sprite E only if collected all C
[] At every move the current number of movements must be displayed in the shell.
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
