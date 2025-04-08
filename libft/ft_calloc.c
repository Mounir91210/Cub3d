/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:36:44 by modavid           #+#    #+#             */
/*   Updated: 2024/06/02 16:17:36 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t ncount, size_t nsize)
{
	size_t	*pointeur;

	pointeur = malloc(nsize * ncount);
	if (pointeur == NULL)
		return (NULL);
	ft_bzero(pointeur, ncount * nsize);
	return (pointeur);
}
