/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 22:46:20 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/27 16:21:50 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

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
	animate(&game);
	mlx_loop(game.mlx);
	return (0);
}
