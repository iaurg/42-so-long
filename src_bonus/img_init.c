/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 21:50:55 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/06 06:47:51 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

static void	*load_img_file(t_game *game, char *file_path)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(game->mlx, file_path, &img_width, &img_height);
	if (!img)
		print_error("Fail to open an image");
	return (img);
}

static void	put_img(t_game *game, int x, int y)
{
	void	*img;
	char	element;

	img = NULL;
	element = game->map.map_array[y][x];
	if (element == PLAYER_CHAR)
	{
		img = game->img.img_player;
		game->player.x = x;
		game->player.y = y;
	}
	else if (element == WALL_CHAR)
		img = game->img.img_wall;
	else if (element == EXIT_CHAR)
	{
		img = game->img.img_exit2;
		game->map.exit_x = x;
		game->map.exit_y = y;
	}
	else if (element == COIN_CHAR)
		img = game->img.img_coin;
	else if (element == FREE_CHAR)
		img = game->img.img_free;
	mlx_put_image_to_window(game->mlx, game->screen, img, x * 32, y * 32);
}

void	render_images(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.row)
	{
		x = 0;
		while (x < game->map.col)
			put_img(game, x++, y);
		y++;
	}
}

void	img_init(t_game *game)
{
	game->img.img_wall = load_img_file(game, WALL_IMG);
	game->img.img_coin = load_img_file(game, COIN_IMG);
	game->img.img_exit = load_img_file(game, EXIT_IMG);
	game->img.img_exit2 = load_img_file(game, EXIT2_IMG);
	game->img.img_free = load_img_file(game, FREE_IMG);
	game->img.img_player = load_img_file(game, PLAYER_IMG);
	render_images(game);
}
