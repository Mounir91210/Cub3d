/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:54:35 by modavid           #+#    #+#             */
/*   Updated: 2025/05/21 00:14:14 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_extension(char *files, char *extension)
{
	if (ft_strrchr(files, '.') == NULL)
		return (1);
	if (ft_strcmp(ft_strrchr(files, '.'), extension) == 0)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_libx	libx;
	// t_pos	*pos;
	int		fd;

	if (ac != 2)
		return (ft_putendl_fd("Error\nBad arguments", 2), 1);
	if (check_extension(av[1], ".cub") == 1)
		return (ft_putendl_fd("Error\nFiles not .cub", 2), 1);
	ft_memset(&data, 0, sizeof(t_data));
	// pos = ft_calloc(1, sizeof(t_pos));
	// if (!pos)
	// 	return (1);
	// data.pos = pos;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd("Error\nNo fd", 2), 1);
	data.texture = take_texture(fd, &data);
	if (data.texture == NULL)
		return (close(fd), 1);
	data.map = take_map(fd, &data);
	if (!data.map)
		return (close(fd), 1);
	close(fd);
	check_texture(&data);
	check_map(&data);
	is_map_open(&data);
	init_mlx(&data, &libx);
	// ft_print2d(data.texture);
	// ft_print2d(data.map);
	free_all(&data);
	return (0);
}
