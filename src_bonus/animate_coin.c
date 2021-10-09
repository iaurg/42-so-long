/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_coin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 06:45:03 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/09 11:27:08 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

static void change_coin(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.img_coin);
	if(game->map.frame == 1)
		game->img.img_coin = load_img_file(game, COIN_IMG);
	else if(game->map.frame == 2)
		game->img.img_coin = load_img_file(game, COIN2_IMG);
	else if (game->map.frame == 3)
		game->img.img_coin = load_img_file(game, COIN3_IMG);
	else if (game->map.frame == 4)
	{
		game->img.img_coin = load_img_file(game, COIN4_IMG);
		game->map.frame = 1;
	}
	game->map.frame++;
}

static void change_exit(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.img_exit);
	game->img.img_exit = load_img_file(game, EXIT_IMG);
}


int	animate_coin(t_game *game)
{
	if (game->map.timer < 1000)
	{
		game->map.timer++;
		return 0;
	}
	game->map.timer = 0;
	change_coin(game);
	if (game->player.count_coins == game->map.coin_char)
		change_exit(game);
	render_images(game);
	return 0;
}
