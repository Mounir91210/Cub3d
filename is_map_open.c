/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_open.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:10:29 by modavid           #+#    #+#             */
/*   Updated: 2025/04/15 19:20:09 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	floodfill(char **map, int x, int y)
// {
// 	// if (x < 0 || y < 0 || ft_strlen2d(map) < x || (int)ft_strlen(map[x]) < y)
// 	// {
// 	// 	printf("%c\n", map[x][y]);
// 	// 	return (1);
// 	// }
// 	if (map[x][y] != '1' && map[x][y] != 'M')
// 		return (1);
// 	map[x][y] = 'M';
// 	floodfill(map, x + 1, y);
// 	floodfill(map, x - 1, y);
// 	floodfill(map, x, y + 1);
// // 	floodfill(map, x, y - 1);
// // 	return (0);
// // }

// void	copy_map(t_data *data)
// {
// 	char	**cpy_map;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	while (data->map[i])
// 		i++;
// 	cpy_map = malloc(sizeof(char *) * (i + 1));
// 	if (!cpy_map)
// 		free_and_exit(data, "Malloc failed");
// 	i = 0;
// 	while (data->map[i])
// 	{
// 		cpy_map[i] = ft_strdup(data->map[i]);
// 		if (!cpy_map[i])
// 		{
// 			ft_free2d(cpy_map);
// 			free_and_exit(data, "Malloc failed");
// 		}
// 		i++;
// 	}
// 	cpy_map[i] = NULL;
// 	check_space(cpy_map[0], &j);
// 	if (floodfill(cpy_map, 0, j) == 1)
// 	{
// 		ft_free2d(cpy_map);
// 		free_and_exit(data, "Map not closed");
// 	}
// }

int	is_not_character(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S'
		&& c != 'W' && c != 'E')
		return (1);
	return (0);
}

void	is_map_open(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0')
			{
				if (is_not_character(data->map[i + 1][j]) == 1)
					free_and_exit(data, "Map not closed");
				if (is_not_character(data->map[i - 1][j]) == 1)
					free_and_exit(data, "Map not closed");
				if (is_not_character(data->map[i][j + 1]) == 1)
					free_and_exit(data, "Map not closed");
				if (is_not_character(data->map[i][j - 1]) == 1)
					free_and_exit(data, "Map not closed");
			}
			j++;
		}
		i++;
	}
}
