/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_coin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 06:45:03 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/07 22:31:45 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

int animate_coin(t_game *game)
{
	game->map.timer++;
	if(game->map.timer % 2 == 0)
		game->img.img_coin = load_img_file(game, COIN_IMG);
	else
		game->img.img_coin = load_img_file(game, COIN2_IMG);
	render_images(game);
	return 0;
}
