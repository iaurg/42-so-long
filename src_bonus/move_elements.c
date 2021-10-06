/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:01:58 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/06 06:47:51 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

static void	play_step(t_game *game)
{
	render_images(game);
	game->player.count_steps++;
	printf("Steps taken: %d\n", game->player.count_steps);
}

static void	move_player(t_game *game, int next_x, int next_y)
{
	int	py;
	int	px;

	py = game->player.y;
	px = game->player.x;
	if (game->map.map_array[next_y][next_x] != WALL_CHAR)
	{
		if (game->map.map_array[next_y][next_x] == EXIT_CHAR
			&& game->player.count_coins == game->map.coin_char)
			game->finished = 1;
		if (game->map.map_array[next_y][next_x] == EXIT_CHAR
			&& game->player.count_coins != game->map.coin_char)
			return ;
		if (game->map.map_array[next_y][next_x] == COIN_CHAR)
			game->player.count_coins++;
		game->map.map_array[next_y][next_x] = PLAYER_CHAR;
		game->player.x = next_x;
		game->map.map_array[py][px] = FREE_CHAR;
		play_step(game);
	}
}

static void	unlock_exit(t_game *game)
{
	void	*img;
	int		ex;
	int		ey;

	img = NULL;
	ex = game->map.exit_x;
	ey = game->map.exit_y;
	img = game->img.img_exit;
	mlx_put_image_to_window(game->mlx, game->screen, img, ex * 32, ey * 32);
}

void	move_elements(int keycode, t_game *game)
{
	int	py;
	int	px;

	py = game->player.y;
	px = game->player.x;
	if (keycode == KEY_A)
		move_player(game, px - 1, py);
	else if (keycode == KEY_D)
		move_player(game, px + 1, py);
	else if (keycode == KEY_W)
		move_player(game, px, py - 1);
	else if (keycode == KEY_S)
		move_player(game, px, py + 1);
	if (game->player.count_coins == game->map.coin_char)
		unlock_exit(game);
	if (!game)
		return ;
}
