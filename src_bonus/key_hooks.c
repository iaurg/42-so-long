/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 22:45:18 by itaureli          #+#    #+#             */
/*   Updated: 2021/11/28 12:19:46 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

static int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	else if (!game)
		return (0);
	else if (game->finished)
		return (0);
	else
		move_elements(keycode, game);
	return (0);
}

int	key_hooks(t_game *game)
{
	mlx_hook(game->screen, EVENT_KEY_PRESS, 1L << 0, &key_hook, game);
	mlx_hook(game->screen, EVENT_X_WIN_PRESS, 1L << 2, &close_game, game);
	mlx_hook(game->screen, EVENT_FOCUS_WIN, 1L << 21, &render_images, game);
	return (0);
}
