/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:04:18 by fardath           #+#    #+#             */
/*   Updated: 2021/10/19 17:31:37 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*len;
	size_t		i;
	size_t		len_s1;
	size_t		len_s2;

	len_s1 = 0;
	len_s2 = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)));
	if (len == NULL)
		return (NULL);
	while (len_s1 < ft_strlen(s1))
	{
		len[i++] = ((char *)s1)[len_s1++];
	}
	while (len_s2 < ft_strlen(s2))
		len[i++] = ((char *)s2)[len_s2++];
	len[i] = '\0';
	return (len);
}
