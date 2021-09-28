/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 21:50:55 by itaureli          #+#    #+#             */
/*   Updated: 2021/09/27 22:46:19 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	img_init(t_game *game)
{
	void *img;
	int width;
	int height;
	img = mlx_xpm_file_to_image(game->mlx, "../assets/sprites/P.xpm", &width, &height);
	if(!img)
		print_error("Error to read image");
	mlx_put_image_to_window(game->mlx, game->screen, img, 1 * 32, 1 * 32);
}
