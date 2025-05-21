/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 01:48:22 by modavid           #+#    #+#             */
/*   Updated: 2025/05/21 02:59:10 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void    put_circle(t_data *data, t_libx *libx)
{
    int     i;
    double  x;
    double  y;
    double  radiant;

    i = 0;
    while (i < 5000)
	{
		radiant = 2 * PIPI * i / 5000;
		x = data->pos.abs + 1 * cos(radiant);
		y = data->pos.ord + 1 * sin(radiant);
		mlx_pixel_put(libx->mlx, libx->win, x * 64, y * 64, 0XFF0000);
		i++;
    }
}

void    put_image(t_data *data, t_libx *libx)
{
    int i;
    int j;

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
    mlx_pixel_put(libx->mlx, libx->win, data->pos.abs * 64, data->pos.ord *64, 0XFF0000);
    double x = data->pos.abs;
    double y = data->pos.ord;
    double dist = 1.3;
    double dist_fov = 0.5;
    
    double xx = x + dist * cos(data->angle);
    double yy = y + dist * sin(data->angle);
    data->vec.abs = xx;
    data->vec.ord = yy;
    // printf("debug => {x: %f} | {y: %f}\n", x, y);
    // printf("debug => {xx: %f} | {yy: %f}\n", xx, yy);
    printf("DEBUG ANGLE => %f\n", data->angle);
    mlx_pixel_put(libx->mlx, libx->win, xx * 64, yy *64, 0XFF0000);
    double perpa = xx + dist_fov * (-sin(data->angle));
    double perpb = yy + dist_fov * (cos(data->angle));
    mlx_pixel_put(libx->mlx, libx->win, perpa * 64, perpb *64, 0XFF0000);
    perpa = xx + dist_fov * (sin(data->angle));
    perpb = yy + dist_fov * (-cos(data->angle));
    mlx_pixel_put(libx->mlx, libx->win, perpa * 64, perpb *64, 0XFF0000);
}

int key_function(int keycode, void *param)
{
    t_data *data;

    data = (t_data *)param;

    if (keycode == 97)
    {
        data->angle += 0.5;
        put_image(data, data->libx);
    }
    return 1;
}

void    init_mlx(t_data *data, t_libx *libx)
{
    int w;
    int l;

    libx->mlx = mlx_init();
    if (libx->mlx == NULL)
        free_and_exit(data, "Mlx init failed");
    libx->win = mlx_new_window(libx->mlx, 1920, 1080, "cub3d");
    libx->white = mlx_xpm_file_to_image(libx->mlx, "white.xpm", &w, &l);
    if (!libx->white)  //w != 64 || l != 64
		free_and_exit(data, "Problem in files");
    //initaliser le vecteur direction par rapport a la direction de depart\
    //creer le plane (camera) ((perpendiculaire))
    //appliquer la formule de raycasting pour lancer les rayon dans le FOV (champ de vision)
    data->libx = libx;
    data->angle = 0;
    put_image(data, libx);
    put_circle(data, libx);
    mlx_key_hook(libx->win, key_function, data);
    mlx_loop(libx->mlx);
}
