/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_map_and_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mounir <mounir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:36:38 by modavid           #+#    #+#             */
/*   Updated: 2025/04/14 15:52:29 by mounir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*export_texture(int fd, t_data *data)
{
	char	*texture;

	texture = ft_strdup("");
	if (!texture)
		return (ft_putendl_fd("Error Malloc", 2), NULL);
	while (1)
	{
		data->tmp_map = get_next_line(fd, 1);
		if (!data->tmp_map)
			return (free(texture), ft_putendl_fd("Error: No map", 2), NULL);
		if (check_no_texture(data->tmp_map) == 1)
			return (texture);
		texture = ft_strjoin(texture, data->tmp_map);
		if (!texture)
			free_and_exit(data, "Error Malloc");
		free(data->tmp_map);
	}
}

char	**take_texture(int fd, t_data *data)
{
	char	*texture;
	char	**texture2d;

	texture = export_texture(fd, data);
	if (!texture)
		return (NULL);
	texture2d = ft_split(texture, '\n');
	if (!texture2d)
	{
		free(texture);
		free_and_exit(data, "Error Malloc");
	}
	return (free(texture), texture2d);
}

char	**take_map(int fd, t_data *data)
{
	char	*map;
	char	**map2d;

	while (1)
	{
		map = get_next_line(fd, 1);
		if (!map)
			break ;
		data->tmp_map = ft_strjoin(data->tmp_map, map);
		if (!data->tmp_map)
		{
			free(map);
			free_and_exit(data, "Error Malloc");
		}
		free(map);
	}
	map2d = ft_split(data->tmp_map, '\n');
	if (!map2d)
		free_and_exit(data, "Error Malloc");
	return (map2d);
}
