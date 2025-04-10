/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:54:35 by modavid           #+#    #+#             */
/*   Updated: 2025/04/10 21:51:35 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_space(char *str, int *i)
{
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\v')
		(*i)++;
}

int	check_extension(char *extension)
{
	if (ft_strcmp(ft_strrchr(extension, '.'), ".cub") == 0)
		return (0);
	return (1);
}

int	check_no_texture(char *str)
{
	int	i;

	i = 0;
	check_space(str, &i);
	if (str[i] != 'N' || str[i] != 'S' || str[i] != 'W'
		|| str[i] != 'E' || str[i] != 'F' || str[i] != 'C')
		return (1);
	return (0);
}

char	**take_texture(int fd)
{
	char	*texture;
	char	*tmp;

	texture = ft_strdup("");
	if (!texture)
		return (ft_putendl_fd("Error Malloc", 2), NULL);
	while (1)
	{
		tmp = get_next_line(fd, 1);
		if (check_no_texture(tmp) == 1)
			break ;
		if (!tmp)
			return (ft_putendl_fd("Error: No map", 2), NULL);
		texture = ft_strjoin(texture, tmp);
		free(tmp);
	}
	
}

char	**take_map(int fd)
{
	char	*map;
	char	*tmp;
	char	**map2d;

	map = ft_strdup("");
	if (!map)
		return (ft_putendl_fd("Error Malloc", 2), NULL);
	while (1)
	{
		tmp = get_next_line(fd, 1);
		if (!tmp)
			break ;
		map = ft_strjoin(map, tmp);
		free(tmp);
	}
	map2d = ft_split(map, '\n');
	if (!map2d)
		return (free(map), ft_putendl_fd("Error Malloc", 2), NULL);
	return (free(map), map2d);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		fd;

	if (ac != 2)
		return (ft_putendl_fd("Error: Bad arguments", 2), 1);
	ft_memset(&data, 0 , sizeof(t_data));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd("Error: fd", 2), 1);
	if (check_extension(av[1]) == 1)
		return (ft_putendl_fd("Error: Files not .cub", 2), 1);
	data.map = take_map(fd);
	if (!data.map)
		return (close(fd), 1);
	close(fd);
	ft_print2d(data.map);
	ft_free2d(data.map);
	return (1);
}
