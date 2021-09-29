/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 21:00:50 by itaureli          #+#    #+#             */
/*   Updated: 2021/09/29 06:44:31 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	window_init(t_game *game)
{
	int	width;
	int	height;

	width = game->map.col * SPRITE_SIZE;
	height = game->map.row * SPRITE_SIZE;
	game->mlx = mlx_init();
	game->screen = mlx_new_window(game->mlx, width, height, "so_long");
}
