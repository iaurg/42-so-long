/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 20:34:48 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/09 16:21:14 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	is_valid_extension(char *map_file)
{
	char	*ext;

	if (!map_file)
		return (0);
	ext = ft_strrchr(map_file, '.');
	if (ft_strncmp(ext, ".ber", 5) == 0)
		return (1);
	print_error("Invalid map extension");
	return (0);
}

static int	is_valid_wall(t_game *game)
{
	int	i;
	int	lst_line;

	i = 0;
	lst_line = game->map.row - 1;
	while (game->map.map_array[0][i] && game->map.map_array[lst_line][i])
	{
		if (game->map.map_array[0][i] != '1')
			return (print_error("Invalid wall"));
		if (game->map.map_array[lst_line][i] != '1')
			return (print_error("Invalid wall"));
		i++;
	}
	i = 0;
	while (i <= lst_line)
	{
		if (game->map.map_array[i][game->map.col - 1] != '1' ||
			game->map.map_array[i][0] != '1')
			return (print_error("Invalid line"));
		i++;
	}
	return (1);
}

static int	is_valid_elements(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < game->map.row)
	{
		while (j < game->map.col)
		{
			if (game->map.map_array[i][j] != PLAYER_CHAR
				&& game->map.map_array[i][j] != COIN_CHAR
				&& game->map.map_array[i][j] != WALL_CHAR
				&& game->map.map_array[i][j] != FREE_CHAR
				&& game->map.map_array[i][j] != EXIT_CHAR)
				return (print_error("Invalid element in map"));
			count_elements(game, game->map.map_array[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

static int	count_map_sides(t_game *game)
{
	int	total_row;
	int	total_col;
	int	total_lst_col;

	total_row = 0;
	total_col = 0;
	total_lst_col = 0;
	while (game->map.map_array[++total_row])
		;
	while (game->map.map_array[0][++total_col])
		;
	while (game->map.map_array[total_row - 1][++total_lst_col])
		;
	if (total_col != total_lst_col)
		return (print_error("Invalid wall"));
	game->map.row = total_row;
	game->map.col = total_col;
	return (1);
}

int	validate_map(t_game *game)
{
	if (!count_map_sides (game)
		||!is_valid_wall(game)
		|| !is_valid_elements(game)
		|| !map_and_validate_elements(game))
		return (0);
	return (1);
}
