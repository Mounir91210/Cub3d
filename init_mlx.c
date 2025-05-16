/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 01:48:22 by modavid           #+#    #+#             */
/*   Updated: 2025/05/16 03:08:46 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_mlx(t_data *data, t_libx *libx)
{
    int i;
    int j;
    int w;
    int l;

    libx->mlx = mlx_init();
    if (libx->mlx == NULL)
        free_and_exit(data, "Mlx init failed");
    libx->win = mlx_new_window(libx->mlx, 1920, 1080, "cub3d");
    libx->white = mlx_xpm_file_to_image(libx->mlx, "white.xpm", &w, &l);
    if (!libx->white)  //w != 64 || l != 64
		free_and_exit(data, "Problem in files");
    i = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == '1')
                mlx_put_image_to_window(libx->mlx, libx->win, libx->white, j * 64, i
                    * 64);
            j++;
        }
        i++;
    }
    mlx_pixel_put(libx->mlx, libx->win, data->pos->abs * 64, data->pos->ord *64, 0XFF0000);
    mlx_loop(libx->mlx);
}
