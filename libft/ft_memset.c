/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:29:42 by modavid           #+#    #+#             */
/*   Updated: 2024/05/27 14:35:02 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tab;
	size_t			i;

	tab = s;
	i = 0;
	while (i < n)
	{
		tab[i] = c;
		i++;
	}
	return (tab);
}

/*
#include <stdio.h>
int	main()
{
	char	tab[] = "idrissa";
	int	 	c = '6';
	size_t  n = 3;
	ft_memset(tab, c, n);
	printf("tab: %s\n", tab);
}
*/