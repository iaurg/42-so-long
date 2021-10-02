/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 22:30:48 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/02 13:53:44 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

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
	exit(0);
	return (0);
}
