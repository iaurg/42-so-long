/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 21:50:55 by itaureli          #+#    #+#             */
/*   Updated: 2021/09/28 06:47:20 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	img_init(t_game *game)
{
	void	*img;
	int		img_width;
	int 	img_height;

	img = mlx_xpm_file_to_image(game->mlx, WALL_IMG, &img_width, &img_height);
	mlx_put_image_to_window(game->mlx, game->screen, img, 0, 0);
}
