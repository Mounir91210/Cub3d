/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mounir <mounir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:06:42 by mounir            #+#    #+#             */
/*   Updated: 2025/04/15 11:04:28 by mounir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    check_element(char *elem, t_data *data)
{
    int j;

    j = 0;
    while (elem[j])
    {
        if (elem[j] != 'N' && elem[j] != 'S' && elem[j] != 'E'
           && elem[j] != 'W' && elem[j] != '0' && elem[j] != '1'
           && elem[j] != ' ' && elem[j] != '\t' && elem[j] != '\v')
           free_and_exit(data, "Wrong character in map");
        j++;
    }
}

void    check_map(t_data *data)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (data->map[i])
    {
        check_element(data->map[i], data);
        count += check_pos_n(data->map[i], data);
        count += check_pos_s(data->map[i], data);
        count += check_pos_w(data->map[i], data);
        count += check_pos_e(data->map[i], data);
        i++;
    }
    if (count < 1)
        free_and_exit(data, "No starting position");
    if (count > 1)
        free_and_exit(data, "Too many starting positions");
}
