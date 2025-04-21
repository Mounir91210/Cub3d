/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:39:08 by modavid           #+#    #+#             */
/*   Updated: 2025/04/21 16:20:38 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_number(char *color)
{
	int	i;

	i = 0;
	while (color[i])
	{
		if (ft_isdigit(color[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	color_range(int color)
{
	if (color < 0 || color > 255)
		return (1);
	return (0);
}

int	take_red_and_green(char *red_green, int *i, t_data *data)
{
	char	*tmp;
	int		count;

	count = *i;
	while (red_green[count] && red_green[count] != ',')
		count++;
	if (count == *i)
		free_and_exit(data, ": No color");
	if (red_green[count] == '\0')
		free_and_exit(data, "Wrong color");
	tmp = malloc(sizeof(char) * count + 1);
	if (!tmp)
		free_and_exit(data, "Malloc failed");
	count = 0;
	while (red_green[*i] != ',')
	{
		tmp[count] = red_green[*i];
		count++;
		(*i)++;
	}
	tmp[count] = '\0';
	(*i)++;
	if (check_number(tmp) == 1)
		free_and_exit(data, "Not number in color range");
	count = ft_atoi_long(tmp);
	return (free(tmp), count);
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
		free_and_exit(data, "Malloc failed");
	count = 0;
	while (blue[*i])
	{
		tmp[count] = blue[*i];
		count++;
		(*i)++;
	}
	tmp[count] = '\0';
	if (check_number(tmp) == 1)
		free_and_exit(data, "Not number in color range");
	count = ft_atoi_long(tmp);
	return (free(tmp), count);
}

void	check_color(char *character, t_data *data)
{
	int	i;

	i = 1;
	if (ft_strncmp(character, "F", 1) == 0)
	{
		check_space(character, &i);
		if (i == 1)
			free_and_exit(data, "No space before RGB color");
		data->f_red = take_red_and_green(character, &i, data);
		data->f_green = take_red_and_green(character, &i, data);
		data->f_blue = take_blue(character, &i, data);
		data->count_f++;
	}
	else if (ft_strncmp(character, "C", 1) == 0)
	{	
		check_space(character, &i);
		if (i == 1)
			free_and_exit(data, "No space before RGB color");
		data->c_red = take_red_and_green(character, &i, data);
		data->c_green = take_red_and_green(character, &i, data);
		data->c_blue = take_blue(character, &i, data);
		data->count_c++;
	}
}
