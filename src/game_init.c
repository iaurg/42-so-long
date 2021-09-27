/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 21:00:50 by itaureli          #+#    #+#             */
/*   Updated: 2021/09/26 21:18:28 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	window_init(t_game *game)
{
	int width; //x
	int height; //y

	width = game->map.col * SPRITE_SIZE;
	height = game->map.row * SPRITE_SIZE;
	// If mlx_init fails to set up the connection to the graphical system, it will return NULL, otherwise a non-null pointer is returned as a connection identifier.
	game->mlx = mlx_init();
	// To calculate screen size get number of rows and columns x tiles size
	game->screen = mlx_new_window(game->mlx, width, height, "so_long");
}
