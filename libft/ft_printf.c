/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:49:25 by modavid           #+#    #+#             */
/*   Updated: 2024/11/02 14:27:01 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_conversion(const char value, va_list args)
{
	if (value == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (value == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (value == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (value == 'd' || value == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (value == 'u')
		return (ft_putnbr_unsign(va_arg(args, unsigned int)));
	else if (value == 'x' || value == 'X')
		return (ft_putnbr_hexa(va_arg(args, unsigned int), value));
	else if (value == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_conversion(str[++i], args);
			if (count == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar(str[i]) == -1)
				return (-1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
