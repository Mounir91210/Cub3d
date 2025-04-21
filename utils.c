/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:17:30 by modavid           #+#    #+#             */
/*   Updated: 2025/04/17 22:35:33 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlen2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	check_space(char *str, int *i)
{
	while (str[*i] && (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\v'))
		(*i)++;
}

void	free_all(t_data *data)
{
	if (data->tmp_map)
		free(data->tmp_map);
	if (data->texture)
		ft_free2d(data->texture);
	if (data->map)
		ft_free2d(data->map);
	if (data->north_path)
		free(data->north_path);
	if (data->south_path)
		free(data->south_path);
	if (data->west_path)
		free(data->west_path);
	if (data->east_path)
		free(data->east_path);
}

void	free_and_exit(t_data *data, char *str)
{
	free_all(data);
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	exit(1);
}
