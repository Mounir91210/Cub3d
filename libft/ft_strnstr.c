/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:53:19 by modavid           #+#    #+#             */
/*   Updated: 2024/06/08 15:10:46 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	if (*s2 == 0)
		return ((char *)s1);
	i = ft_strlen(s2);
	while (*s1 && i <= len)
	{
		if (*s1 == *s2 && ft_strncmp(s1, s2, i) == 0)
			return ((char *)s1);
		s1++;
		len--;
	}
	return (NULL);
}
