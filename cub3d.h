/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:58:24 by modavid           #+#    #+#             */
/*   Updated: 2025/05/17 01:01:31 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <math.h>
# include <fcntl.h>

# define PIPI 3.14159265358979323846

typedef	struct s_libx
{
	void	*mlx;
	void	*win;
	void	*white;
	void	*black;
	
}	t_libx;

typedef struct s_pos
{
	int	abs;
	int	ord;
}	t_pos;

typedef struct s_data
{
	char	**map;
	char	**texture;
	char	*tmp_map;
	char	*north_path;
	int		count_north;
	char	*south_path;
	int		count_south;
	char	*west_path;
	int		count_west;
	char	*east_path;
	int		count_east;
	int		f_red;
	int		f_green;
	int		f_blue;
	int		count_f;
	int		c_red;
	int		c_green;
	int		c_blue;
	int		count_c;
	int		pos_n;
	int		pos_w;
	int		pos_s;
	int		pos_e;
	t_pos	*pos;
}	t_data;

void	free_and_exit(t_data *data, char *str);
void	free_all(t_data *data);
int		ft_strlen2d(char **str);
char	**take_map(int fd, t_data *data);
char	**take_texture(int fd, t_data *data);
void	check_color(char *character, t_data *data);
void	check_texture(t_data *data);
int		check_no_texture(char *str);
void	check_space(char *str, int *i);
int		color_range(int color);
void	check_map(t_data *data);
int		check_pos_n(char *player, t_data *data, int i);
int		check_pos_s(char *player, t_data *data, int i);
int		check_pos_w(char *player, t_data *data, int i);
int		check_pos_e(char *player, t_data *data, int i);
void	is_map_open(t_data *data);
int		check_extension(char *files, char *extension);

// minilibx
void    init_mlx(t_data *data, t_libx *libx);

#endif