/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:39:12 by modavid           #+#    #+#             */
/*   Updated: 2025/04/13 14:17:02 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_no_texture(char *str)
{
	int	i;

	i = 0;
	// check_space(str, &i);
	if (str[i] == '\0' && str[i] != 'N' && str[i] != 'S' && str[i] != 'W' && str[i] != 'C'
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
	tmp = malloc(sizeof(char) * count + 1);
	if (!tmp)
		free_and_exit(data, "Error Malloc");
	count = 0;
	while (path[*i] && path[*i] != '\n' && path[*i] != ' '
		&& path[*i] != '\t' && path[*i] != '\v')
	{
		tmp[count] = path[*i];
		count++;
		(*i)++;
	}
	tmp[count] = '\0';
	return (tmp);
}

void	check_character(char *character, t_data *data)
{
	int	i;

	i = 3;
	if (ft_strncmp(character, "NO ", 3) == 0)
	{
		check_space(character, &i);
		data->north = path_of_texture(character, &i, data);
	}
	else if (ft_strncmp(character, "SO ", 3) == 0)
	{
		check_space(character, &i);
		data->south = path_of_texture(character, &i, data);
	}
	else if (ft_strncmp(character, "WE ", 3) == 0)
	{
		check_space(character, &i);
		data->west = path_of_texture(character, &i, data);
	}
	else if (ft_strncmp(character, "EA ", 3) == 0)
	{
		check_space(character, &i);
		data->east = path_of_texture(character, &i, data);
	}
}

void	check_texture(t_data *data)
{
	int	i;

	i = 0;
	while (data->texture[i])
	{
		check_character(data->texture[i], data);
		check_color(data->texture[i], data);
		i++;
	}
}
