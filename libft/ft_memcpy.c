/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:49:45 by modavid           #+#    #+#             */
/*   Updated: 2024/05/30 19:26:20 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tab;
	unsigned char	*tabs;
	size_t			i;

	tab = (unsigned char *)dest;
	tabs = (unsigned char *)src;
	i = 0;
	if (tab == NULL && tabs == NULL)
		return (NULL);
	while (i < n)
	{
		tab[i] = tabs[i];
		i++;
	}
	return (tab);
}

/*
#include <stdio.h>
int	main()
{
	char	tab[] = "idrissa";
	char	tabs[]= "mou";
	size_t  n = 3;
	ft_memcpy(tab, tabs, n);
	printf("tab: %s\n", tab);
}
*/