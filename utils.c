/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mounir <mounir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:17:30 by modavid           #+#    #+#             */
/*   Updated: 2025/04/14 15:27:56 by mounir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	if (data->north)
		free(data->north);
	if (data->south)
		free(data->south);
	if (data->west)
		free(data->west);
	if (data->east)
		free(data->east);
}

void	free_and_exit(t_data *data, char *str)
{
	free_all(data);
	ft_printf("%s\n", str);
	exit(1);
}
