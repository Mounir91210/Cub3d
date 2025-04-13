/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:39:08 by modavid           #+#    #+#             */
/*   Updated: 2025/04/13 16:58:19 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_number(char *color)
{
	int	i;

	i = 0;
	while (color[i])
	{
		printf("number n%d = %c\n", i, color[i]);
		if (ft_isdigit(color[i]) == 0)
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
	(*i)++;
	if (check_number(tmp) == 1)
		free_and_exit(data, "Error: Not number in color range");
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
	if (check_number(tmp) == 1)
		free_and_exit(data, "Error: Not number in color range");
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
		printf("red color = %d\n", data->f_red);
		data->f_green = take_red_and_green(character, &i, data);
		printf("green color = %d\n", data->f_green);
		data->f_blue = take_blue(character, &i, data);
		printf("blue color = %d\n", data->f_blue);
		if (color_range(data->f_blue) == 1 || color_range(data->f_red) == 1
			|| color_range(data->f_green) == 1)
			free_and_exit(data, "Error: Wrong color range");
	}
	else if (ft_strncmp(character, "C ", 2) == 0)
	{	
		check_space(character, &i);
		data->c_red = take_red_and_green(character, &i, data);
		data->c_green = take_red_and_green(character, &i, data);
		data->c_blue = take_blue(character, &i, data);
		if (color_range(data->c_blue) == 1 || color_range(data->c_red) == 1
			|| color_range(data->c_green) == 1)
			free_and_exit(data, "Error: Wrong color range");
	}
}
