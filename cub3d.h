/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mounir <mounir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:58:24 by modavid           #+#    #+#             */
/*   Updated: 2025/04/14 15:20:05 by mounir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"

typedef struct s_data
{
	char	**map;
	char	**texture;
	char	*tmp_map;
	char	*north;
	int		count_north;
	char	*south;
	int		count_south;
	char	*west;
	int		count_west;
	char	*east;
	int		count_east;
	int		f_red;
	int		f_green;
	int		f_blue;
	int		c_red;
	int		c_green;
	int		c_blue;
}	t_data;	

void	free_and_exit(t_data *data, char *str);
void	free_all(t_data *data);
char	**take_map(int fd, t_data *data);
char	**take_texture(int fd, t_data *data);
void	check_color(char *character, t_data *data);
void	check_texture(t_data *data);
int		check_no_texture(char *str);
void	check_space(char *str, int *i);
int		color_range(int color);

#endif