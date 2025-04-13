/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:39:08 by modavid           #+#    #+#             */
/*   Updated: 2025/04/13 13:40:29 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	take_red_and_green(char *red_green, int *i, t_data *data)
{
	char	*tmp;
	int		count;

	count = *i;
	while (red_green[count] && red_green[count] != ',')
		count++;
	if (red_green[count] == '\0')
		free_and_exit(data, "Error: Wrong color");
	tmp = malloc(sizeof(char) * count + 1);
	if (!tmp)
		free_and_exit(data, "Error Malloc");
	count = 0;
	while (red_green[*i] != ',')
	{
		tmp[count] = red_green[*i];
		count++;
		(*i)++;
	}
	tmp[count] = '\0';
	return (ft_atoi_long(tmp));
}

int	take_blue(char *blue, int *i, t_data *data)
{
	char	*tmp;
	int		count;

	count = *i;
	while (blue[count])
		count++;
	tmp = malloc(sizeof(char) * count + 1);
	if (!tmp)
		free_and_exit(data, "Error Malloc");
	count = 0;
	while (blue[*i])
	{
		tmp[count] = blue[*i];
		count++;
		(*i)++;
	}
	tmp[count] = '\0';
	return (ft_atoi_long(tmp));
}

void	check_color(char *character, t_data *data)
{
	int	i;

	i = 2;
	if (ft_strncmp(character, "F ", 2) == 0)
	{
		check_space(character, &i);
		data->f_red = take_red_and_green(character, &i, data);
		data->f_blue = take_blue(character, &i, data);
		data->f_green = take_red_and_green(character, &i, data);
		if (data->f_blue < 0 || data->f_blue > 255 || data->f_green < 0
			|| data->f_green < 255 || data->f_red < 0 || data->f_red < 255)
			free_and_exit(data, "Error: Wrong color range");
	}
	else if (ft_strncmp(character, "C ", 2) == 0)
	{	
		check_space(character, &i);
		data->c_red = take_red_and_green(character, &i, data);
		data->c_blue = take_blue(character, &i, data);
		data->c_green = take_red_and_green(character, &i, data);
		if (data->f_blue < 0 || data->f_blue > 255 || data->f_green < 0
			|| data->f_green < 255 || data->f_red < 0 || data->f_red < 255)
			free_and_exit(data, "Error: Wrong color range");
	}
}
