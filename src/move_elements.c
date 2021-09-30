/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:01:58 by itaureli          #+#    #+#             */
/*   Updated: 2021/09/30 09:54:33 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	move_elements(int keycode, t_game *game)
{
	if (keycode == KEY_A)
		printf("move_left");
	else if (keycode == KEY_D)
		printf("move_right");
	else if (keycode == KEY_S)
		printf("move_down");
	else if (keycode == KEY_W)
		printf("move_up");
	if (!game)
		return;
}
