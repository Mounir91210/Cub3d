/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modavid <modavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:31:20 by modavid           #+#    #+#             */
/*   Updated: 2024/10/06 17:49:16 by modavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atoi_long(const char *str)
{
	long	i;
	long	nb;
	long	sg;

	i = 0;
	sg = 1;
	nb = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sg = sg * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i++] - '0';
		if (nb * sg > 2147483647 || nb * sg < -2147483648)
			return (2147483648);
	}
	return (nb * sg);
}
