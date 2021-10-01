/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:01:58 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/01 06:26:49 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static void move_left(t_game *game)
{
	int py;
	int px;

	py = game->player.y;
	px = game->player.x;
	if (game->map.map_array[py][px - 1] == WALL_CHAR)
		return;
	game->map.map_array[py][px - 1] = PLAYER_CHAR;
	game->player.x = px - 1;
	game->map.map_array[py][px] = FREE_CHAR;
	render_images(game);
}

static void move_right(t_game *game)
{
	int py;
	int px;

	py = game->player.y;
	px = game->player.x;

	if (game->map.map_array[py][px + 1] == WALL_CHAR)
		return;
	game->map.map_array[py][px + 1] = PLAYER_CHAR;
	game->player.x = px + 1;
	game->map.map_array[py][px] = FREE_CHAR;
	if (game->map.map_array[py][px - 1] != WALL_CHAR)
		game->map.map_array[py][px - 1] = FREE_CHAR;
	render_images(game);
}

static void move_up(t_game *game)
{
	int py;
	int px;

	py = game->player.y;
	px = game->player.x;

	if (game->map.map_array[py - 1][px] == WALL_CHAR)
		return;
	game->map.map_array[py - 1][px] = PLAYER_CHAR;
	game->player.y = py - 1;
	if (game->map.map_array[py - 1][px] != WALL_CHAR)
		game->map.map_array[py][px] = FREE_CHAR;
	render_images(game);
}

static void move_down(t_game *game)
{
	int py;
	int px;

	py = game->player.y;
	px = game->player.x;

	if (game->map.map_array[py + 1][px] == WALL_CHAR)
		return;
	game->map.map_array[py + 1][px] = PLAYER_CHAR;
	game->player.y = py + 1;
	if (game->map.map_array[py + 1][px] != WALL_CHAR)
		game->map.map_array[py][px] = FREE_CHAR;
	render_images(game);
}

void	move_elements(int keycode, t_game *game)
{
	if (keycode == KEY_A)
		move_left(game);
	else if (keycode == KEY_D)
		move_right(game);
	else if (keycode == KEY_W)
		move_up(game);
	else if (keycode == KEY_S)
		move_down(game);
	if (!game)
		return;
}
