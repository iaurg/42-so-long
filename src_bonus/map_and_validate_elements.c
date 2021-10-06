/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_and_validate_elements.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 07:04:51 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/06 06:47:51 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	count_elements(t_game *game, char element)
{
	if (element == PLAYER_CHAR)
		game->map.player_char++;
	else if (element == COIN_CHAR)
		game->map.coin_char++;
	else if (element == EXIT_CHAR)
		game->map.exit_char++;
}

int	map_and_validate_elements(t_game *game)
{
	if (game->map.player_char != 1)
		return (print_error("Map must have one P"));
	else if (game->map.coin_char < 1)
		return (print_error("Map must at least have one C"));
	else if (game->map.exit_char != 1)
		return (print_error("Map must have one E"));
	return (1);
}
