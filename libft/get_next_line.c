/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:25:03 by modavid           #+#    #+#             */
/*   Updated: 2024/11/03 17:16:00 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **str)
{
	free (*str);
	*str = NULL;
}

void	ft_clear_line(char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
	{
		line[0] = '\0';
		return ;
	}
	i++;
	while (line[i])
	{
		line[j] = line[i];
		j++;
		i++;
	}
	line[j] = '\0';
}

char	*get_next_line(int fd, int flag)
{
	char		*buffer;
	char		*last;
	static char	*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE < 1 || flag == 0)
		return (free(line), line = NULL, NULL);
	if (!line)
		line = ft_strdup("");
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (free(buffer), NULL);
	free((buffer[0] = '\0', bytes_read = 1, NULL));
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_free(&buffer), ft_free(&line), NULL);
		buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
	}
	if (bytes_read == 0 && !line[0])
		return (ft_free(&line), free(buffer), NULL);
	free((last = ft_strdup(line), ft_clear_line(line), buffer));
	return (last);
}
