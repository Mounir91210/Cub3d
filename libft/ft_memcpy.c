/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:49:45 by modavid           #+#    #+#             */
/*   Updated: 2025/04/13 14:59:53 by modavid          ###   ########.fr       */
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
