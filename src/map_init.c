/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 06:47:00 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/02 13:49:19 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

char	**generate_map_array(char *map_file)
{
	int		file_descriptor;
	char	*temp;
	char	*map_string;
	char	*temp_map;
	char	**result;

	file_descriptor = open(map_file, O_RDONLY);
	map_string = ft_strdup("");
	while (1)
	{
		temp = get_next_line(file_descriptor);
		if (!temp)
			break ;
		temp_map = map_string;
		map_string = ft_strjoin(temp_map, temp);
		free_and_reset(temp);
		free_and_reset(temp_map);
	}
	result = ft_split(map_string, '\n');
	free_and_reset(map_string);
	map_string = NULL;
	close(file_descriptor);
	return (result);
}

void	map_init(t_game *game)
{
	game->map.coin_char = 0;
	game->map.player_char = 0;
	game->map.exit_char = 0;
	game->player.count_steps = 0;
	game->player.count_coins = 0;
	game->finished = 0;
}
