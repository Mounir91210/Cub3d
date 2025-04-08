/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:12:38 by modavid           #+#    #+#             */
/*   Updated: 2025/04/08 14:17:56 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_all(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static size_t	ft_countlen(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static size_t	ft_countword(char const *str, char c)
{
	size_t	i;
	size_t	ammo;
	size_t	words;

	i = 0;
	words = 0;
	ammo = 1;
	while (str[i])
	{
		if (ammo == 1 && str[i] != c)
		{
			ammo = 0;
			words++;
		}
		if (str[i] == c)
			ammo = 1;
		i++;
	}
	return (words);
}

static char	**ft_returntab(char **tab, char const *str, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (str[i])
	{
		k = 0;
		while (str[i] == c)
			i++;
		if (str[i] == '\0')
			break ;
		tab[j] = malloc(sizeof(char) * (ft_countlen(str + i, c) + 1));
		if (!tab)
			return (ft_free_all(tab), NULL);
		while (str[i] != c && str[i])
		{
			tab[j][k++] = str[i];
			i++;
		}
		tab[j++][k] = '\0';
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	tab = malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (!tab)
		return (NULL);
	ft_returntab(tab, s, c);
	return (tab);
}

// int	main()
// {
// 	char	**split;
// 	int		i;

// 	i = 0;
// 	split = ft_split("yo bienou   ", ' ');
// 	while (split[i])
// 	{
// 		printf("%s$\n", split[i]);
// 		i++;
// 	}
// 	return (0);
// }
