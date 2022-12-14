/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleaf <bleaf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:58:40 by sherbert          #+#    #+#             */
/*   Updated: 2022/11/06 23:29:46 by bleaf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numwords(char const *s, char c)
{
	int	words;
	int	if_word;

	words = 0;
	if_word = 1;
	while (*s)
	{
		if (*s == c)
			if_word = 1;
		else if (if_word == 1)
		{
			if_word = 0;
			words++;
		}
		s++;
	}
	return (words);
}

static int	ft_numchars(char const *s, char c, int i)
{
	int	chars;

	chars = 0;
	while (s[i] != c && s[i] != '\0')
	{
		chars++;
		i++;
	}
	return (chars);
}

static char	**ft_free_split(char **src, int i)
{
	while (i > 0)
	{
		i--;
		free((void *)src[i]);
	}
	free((void *)src);
	return (NULL);
}

char	**ft_if_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	split = (char **)malloc(sizeof(char *) * (ft_numwords(s, c) + 1));
	if (!split)
		return (NULL);
	while (i < ft_numwords(s, c) && s[j])
	{
		k = 0;
		while (s[j] == c)
			j++;
		split[i] = (char *)malloc(sizeof(char) * (ft_numchars(s, c, j) + 1));
		if (!split)
			return (ft_free_split(split, i));
		while (s[j] != c && s[j] != '\0')
			split[i][k++] = s[j++];
		split[i][k] = '\0';
		i++;
	}
	split[i] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	if (s == NULL)
		return (NULL);
	else
		return (ft_if_split(s, c));
}
