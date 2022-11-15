/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleaf <bleaf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 14:14:29 by sherbert          #+#    #+#             */
/*   Updated: 2022/11/06 23:25:32 by bleaf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(int nb)
{
	int	sign;

	sign = 1;
	if (nb < 0)
	{
		sign = -1;
		nb = nb * -1;
	}
	return (sign);
}

static int	ft_len(int nb)
{
	int		i;
	int		nbr;

	nbr = nb;
	i = 0;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		i++;
	}
	while (nbr >= 10)
	{
		i++;
		nbr = nbr / 10;
	}
	i++;
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int	i;
	int				sign;
	char			*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_len(n);
	sign = ft_sign(n);
	if (sign == -1)
		n *= -1;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (n == 0)
		str[--i] = '0';
	while (n)
	{
		i--;
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
