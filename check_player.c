/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mounir <mounir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:53:46 by mounir            #+#    #+#             */
/*   Updated: 2025/04/15 11:01:15 by mounir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_pos_n(char *player, t_data *data)
{
    int j;
    int count;

    j = 0;
    count = 0;
    while (player[j])
    {
        if (player[j] == 'N')
        {
            data->pos_N = 1;
            count++;
        }
        j++;
    }
    return (count);
}

int check_pos_s(char *player, t_data *data)
{
    int j;
    int count;

    j = 0;
    count = 0;
    while (player[j])
    {
        if (player[j] == 'S')
        {
            data->pos_S = 1;
            count++;
        }
        j++;
    }
    return (count);
}

int check_pos_w(char *player, t_data *data)
{
    int j;
    int count;

    j = 0;
    count = 0;
    while (player[j])
    {
        if (player[j] == 'W')
        {
            data->pos_W= 1;
            count++;
        }
        j++;
    }
    return (count);
}

int check_pos_e(char *player, t_data *data)
{
    int j;
    int count;

    j = 0;
    count = 0;
    while (player[j])
    {
        if (player[j] == 'E')
        {
            data->pos_E = 1;
            count++;
        }
        j++;
    }
    return (count);
}
