/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_map_and_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:36:38 by modavid           #+#    #+#             */
/*   Updated: 2025/04/13 22:51:50 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**take_texture(int fd)
{
	char	*texture;
	char	*tmp;
	char	**tmp2d;

	texture = ft_strdup("");
	if (!texture)
		return (ft_putendl_fd("Error Malloc", 2), NULL);
	while (1)
	{
		tmp = get_next_line(fd, 1);
		if (!tmp)
			return (ft_putendl_fd("Error: No map", 2), NULL);
		if (check_no_texture(tmp) == 1)
		{
			free(tmp);
			break ;
		}
		texture = ft_strjoin(texture, tmp);
		if (!texture)
			return (free(tmp), ft_putendl_fd("Error: No map", 2), NULL);
		free(tmp);
	}
	tmp2d = ft_split(texture, '\n');
	if (!tmp2d)
		return (free(texture), ft_putendl_fd("Error Malloc", 2), NULL);
	return (free(texture), tmp2d);
}

char	**take_map(int fd, t_data *data)
{
	char	*map;
	char	*tmp;
	char	**map2d;

	map = ft_strdup("");
	if (!map)
		free_and_exit(data, "Error Malloc");
	while (1)
	{
		tmp = get_next_line(fd, 1);
		if (!tmp)
			break ;
		map = ft_strjoin(map, tmp);
		if (!map)
		{
			free(tmp);
			free_and_exit(data, "Error Malloc");
		}
		free(tmp);
	}
	map2d = ft_split(map, '\n');
	if (!map2d)
	{
		free(map);
		free_and_exit(data, "Error Malloc");
	}
	return (free(map), map2d);
}
