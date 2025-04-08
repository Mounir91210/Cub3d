/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:04:45 by modavid           #+#    #+#             */
/*   Updated: 2024/11/02 14:26:42 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(unsigned long nb, char *base)
{
	int	base_len;
	int	count;

	base_len = 0;
	count = 0;
	while (base[base_len])
		base_len++;
	if (nb >= (unsigned long) base_len)
	{
		count += ft_putnbr_base(nb / base_len, base);
		count += ft_putnbr_base(nb % base_len, base);
	}
	else
		count += ft_putchar(base[nb]);
	return (count);
}
