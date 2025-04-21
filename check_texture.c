/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:39:12 by modavid           #+#    #+#             */
/*   Updated: 2025/04/21 16:49:04 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_no_texture(char *str)
{
	int	i;

	i = 0;
	check_space(str, &i);
	if (str[i] != 'N' && str[i] != 'S' && str[i] != 'W' && str[i] != 'C'
		&& str[i] != 'E' && str[i] != 'F' && str[i] != '\n' && str[i] != ' ')
		return (1);
	return (0);
}

char	*path_of_texture(char *path, int *i, t_data *data)
{
	char	*tmp;
	int		count;

	count = *i;
	while (path[count] && path[count] != '\n' && path[count] != ' '
		&& path[count] != '\t' && path[count] != '\v')
		count++;
	if (count == *i)
		free_and_exit(data, "No texture path");
	tmp = malloc(sizeof(char) * count + 1);
	if (!tmp)
		free_and_exit(data, "Malloc failed");
	count = 0;
	while (path[*i] && path[*i] != '\n' && path[*i] != ' '
		&& path[*i] != '\t' && path[*i] != '\v')
	{
		tmp[count] = path[*i];
		count++;
		(*i)++;
	}
	tmp[count] = '\0';
	check_space(path, i);
	if (path[*i] != '\0' || path[*i] != '\n')
		free_and_exit(data, "wrong character after texture path");
	return (tmp);
}

void	check_east_and_west(char *character, t_data *data)
{
	int	i;

	i = 2;
	if (ft_strncmp(character, "WE", 2) == 0)
	{
		check_space(character, &i);
		if (i == 2)
			free_and_exit(data, "No space before texture path");
		data->west_path = path_of_texture(character, &i, data);
		data->count_west++;
	}
	else if (ft_strncmp(character, "EA", 2) == 0)
	{
		check_space(character, &i);
		if (i == 2)
			free_and_exit(data, "No space before texture path");
		data->east_path = path_of_texture(character, &i, data);
		data->count_east++;
	}
}

void	check_north_and_south(char *character, t_data *data)
{
	int	i;

	i = 2;
	if (ft_strncmp(character, "NO", 2) == 0)
	{
		check_space(character, &i);
		if (i == 2)
			free_and_exit(data, "No space before texture path");
		data->north_path = path_of_texture(character, &i, data);
		data->count_north++;
	}
	else if (ft_strncmp(character, "SO", 2) == 0)
	{
		check_space(character, &i);
		if (i == 2)
			free_and_exit(data, "No space before texture path");
		data->south_path = path_of_texture(character, &i, data);
		data->count_south++;
	}
}

void	check_texture(t_data *data)
{
	int	i;

	i = 0;
	while (data->texture[i])
	{
		check_north_and_south(data->texture[i], data);
		check_east_and_west(data->texture[i], data);
		check_color(data->texture[i], data);
		i++;
	}
	if (data->count_south != 1 || data->count_north != 1 || data->count_f != 1
		|| data->count_west != 1 || data->count_east != 1 || data->count_c != 1)
		free_and_exit(data, "Wrong number of ID");
	if (color_range(data->c_blue) == 1 || color_range(data->c_red) == 1
		|| color_range(data->c_green) == 1 || color_range(data->f_blue) == 1
		|| color_range(data->f_red) == 1 || color_range(data->f_green) == 1)
		free_and_exit(data, "Wrong color range");
}
