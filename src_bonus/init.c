/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 22:46:20 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/04 06:27:40 by itaureli         ###   ########.fr       */
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
[x] Validate Map at least one exit, one collectible, one starting position.
[x] Init window with right size
[x] Print sprites on screen
[x] Close window when click on "X"
[x] Close window when hit ESC
[] Validate SIGSERV on game exit (quit the program cleanly.)
[] Check if all local functions are static
[] Validate norminette
[] Add header42

Move
[x] Move character (WASD)
[x] The player must be able to move up,down,left,right
[x] Player cannot move into walls
[x] Count coins
[x] Show steps on terminal
[x] Collect coins
[x] At every move the current number of movements must be displayed in the shell.
[x] Allow exit into sprite E only if collected all C
[x] Validate invalid_map_wall map
[] mlx_loop_hook + contador de tempo para alternar as animações
*/

int	main(int argc, char **argv)
{
	t_game	game;

	setbuf(stdout, NULL);
	if (argc != 2)
		return (print_error("Invalid number of arguments"));
	if (!is_valid_extension(argv[1]))
		return (0);
	game.map.map_array = generate_map_array(argv[1]);
	map_init(&game);
	if (!validate_map(&game))
		return (0);
	window_init(&game);
	img_init(&game);
	key_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
