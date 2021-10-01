/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 06:47:00 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/01 06:47:02 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

char **generate_map_array(char *map_file)
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
		if (!temp) break;
		temp_map = map_string;
		map_string = ft_strjoin(temp_map, temp);
		free(temp);
		free(temp_map);
	}
	result = ft_split(map_string, '\n');
	close(file_descriptor);
	return (result);
}
