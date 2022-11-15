/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleaf <bleaf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 17:24:03 by sherbert          #+#    #+#             */
/*   Updated: 2022/11/06 23:28:23 by bleaf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	unsigned char		*str;
	size_t				i;

	dst = (unsigned char *)dest;
	str = (unsigned char *)src;
	if (dst == NULL && str == NULL)
		return (NULL);
	i = -1;
	if (str < dst)
		while ((int)(--n) >= 0)
			dst[n] = str[n];
	else
		while (++i < n)
			dst[i] = str[i];
	return (dst);
}
