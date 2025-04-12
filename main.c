/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:54:35 by modavid           #+#    #+#             */
/*   Updated: 2025/04/13 00:09:55 by modavid          ###   ########.fr       */
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
	if (str[i] != 'N' || str[i] != 'S' || str[i] != 'W' || str[i] != 'C'
		|| str[i] != 'E' || str[i] != 'F' || str[i] != '\n')
		return (1);
	return (0);
}

char	*path_of_texture(char *path, int *i)
{
	char	*tmp;
	int		count;

	count = *i;
	while (path[count] && path[count] != '\n' && path[count] != ' '
		&& path[count] != '\t' && path[count] != '\v')
		count++;
	tmp = malloc(sizeof(char) * count + 1);
	if (!tmp)
		free_and_exit("Error Malloc");
	count = 0;
	while (path[*i] && path[*i] != '\n' && path[*i] != ' '
		&& path[*i] != '\t' && path[*i] != '\v')
	{
		tmp[count] = path[*i];
		count++;
		(*i)++;
	}
	tmp[count] = '\0';
	return (tmp);
}

int	take_red_and_green(char *red_green, int *i)
{
	char	*tmp;
	int		count;

	count = *i;
	while (red_green[count] && red_green[count] != ',')
		count++;
	if (red_green[count] == '\0')
		free_and_exit("Error: Wrong color");
	tmp = malloc(sizeof(char) * count + 1);
	if (!tmp)
		free_and_exit("Error Malloc");
	count = 0;
	while (red_green[*i] != ',')
	{
		tmp[count] = red_green[*i];
		count++;
		(*i)++;
	}
	tmp[count] = '\0';
	return (ft_atoi_long(tmp));
}

int	take_blue(char *blue, int *i)
{
	char	*tmp;
	int		count;

	count = *i;
	while (blue[count])
		count++;
	tmp = malloc(sizeof(char) * count + 1);
	if (!tmp)
		free_and_exit("Error Malloc");
	count = 0;
	while (blue[*i])
	{
		tmp[count] = blue[*i];
		count++;
		(*i)++;
	}
	tmp[count] = '\0';
	return (ft_atoi_long(tmp));
}

void	check_character2(char *character, t_data *data)
{
	int	i;

	i = 2;
	if (ft_strncmp(character, "F ", 2) == 0)
	{
		check_space(character, &i);
		data->f_red = take_red_and_green(character, &i);
		data->f_blue = take_blue(character, &i);
		data->f_green = take_red_and_green(character, &i);
		if (data->f_blue < 0 || data->f_blue > 255 || data->f_green < 0
			|| data->f_green < 255 || data->f_red < 0 || data->f_red < 255)
			free_and_exit("Error: Wrong color range");
	}
	else if (ft_strncmp(character, "C ", 2) == 0)
	{	
		check_space(character, &i);
		data->c_red = take_red_and_green(character, &i);
		data->c_blue = take_blue(character, &i);
		data->c_green = take_red_and_green(character, &i);
		if (data->f_blue < 0 || data->f_blue > 255 || data->f_green < 0
			|| data->f_green < 255 || data->f_red < 0 || data->f_red < 255)
			free_and_exit("Error: Wrong color range");
	}
}

void	check_character(char *character, t_data *data)
{
	int	i;

	i = 3;
	if (ft_strncmp(character, "NO ", 3) == 0)
	{
		check_space(character, &i);
		data->north = path_of_texture(character, &i);
	}
	else if (ft_strncmp(character, "SO ", 3) == 0)
	{
		check_space(character, &i);
		data->south = path_of_texture(character, &i);
	}
	else if (ft_strncmp(character, "WE ", 3) == 0)
	{
		check_space(character, &i);
		data->west = path_of_texture(character, &i);
	}
	else if (ft_strncmp(character, "EA ", 3) == 0)
	{
		check_space(character, &i);
		data->east = path_of_texture(character, &i);
	}
}

void	check_texture(char **texture, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (texture[i])
	{
		check_character(texture[i], data);
		check_character2(texture[i], data);
		i++;
	}
}

char	**take_texture(int fd, t_data *data)
{
	char	*texture;
	char	*tmp;
	char	**tmp2d;

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
	tmp2d = ft_split(texture, '\n');
	if (!tmp2d)
		return (free(texture), ft_putendl_fd("Error Malloc", 2), NULL);
	free(texture);
	check_texture(tmp2d, data);
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
