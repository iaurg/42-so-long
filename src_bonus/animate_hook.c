/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 06:46:23 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/06 06:50:22 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void animate(t_game *game)
{
	mlx_loop_hook(game->mlx, &animate_coin, game);
}
