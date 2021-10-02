/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 22:30:48 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/02 16:44:08 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void free_map(char **map_array)
{
	int i;
	i = 0;
	while(map_array[i])
		free_and_reset(map_array[i++]);
	free_and_reset(map_array);
}

int	close_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.img_wall);
	mlx_destroy_image(game->mlx, game->img.img_coin);
	mlx_destroy_image(game->mlx, game->img.img_exit);
	mlx_destroy_image(game->mlx, game->img.img_exit2);
	mlx_destroy_image(game->mlx, game->img.img_free);
	mlx_destroy_image(game->mlx, game->img.img_player);
	mlx_destroy_window(game->mlx, game->screen);
	mlx_destroy_display(game->mlx);
	free_and_reset(game->mlx);
	free_map(game->map.map_array);
	exit(0);
	return (0);
}
