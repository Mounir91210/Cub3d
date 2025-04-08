/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:59:32 by modavid           #+#    #+#             */
/*   Updated: 2024/11/02 14:22:59 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(void *ptr)
{
	unsigned long	pt;
	int				len;

	len = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	else
	{
		pt = (unsigned long long)ptr;
		len += write(1, "0x", 2);
		len += ft_putnbr_base(pt, "0123456789abcdef");
	}
	return (len);
}
