/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:04:03 by modavid           #+#    #+#             */
/*   Updated: 2024/11/02 14:26:14 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_hexa(unsigned int nb, const char base)
{
	int	count;

	count = 0;
	if (base == 'x')
		count += ft_putnbr_base(nb, "0123456789abcdef");
	else
		count += ft_putnbr_base(nb, "0123456789ABCDEF");
	return (count);
}
