/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:53:46 by mounir            #+#    #+#             */
/*   Updated: 2025/04/15 15:28:05 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_pos_n(char *player, t_data *data)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (player[j])
	{
		if (player[j] == 'N')
		{
			data->pos_n = 1;
			count++;
		}
		j++;
	}
	return (count);
}

int	check_pos_s(char *player, t_data *data)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (player[j])
	{
		if (player[j] == 'S')
		{
			data->pos_s = 1;
			count++;
		}
		j++;
	}
	return (count);
}

int	check_pos_w(char *player, t_data *data)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (player[j])
	{
		if (player[j] == 'W')
		{
			data->pos_w = 1;
			count++;
		}
		j++;
	}
	return (count);
}

int	check_pos_e(char *player, t_data *data)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (player[j])
	{
		if (player[j] == 'E')
		{
			data->pos_e = 1;
			count++;
		}
		j++;
	}
	return (count);
}
