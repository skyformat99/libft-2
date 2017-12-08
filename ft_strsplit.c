/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 20:01:53 by ssong             #+#    #+#             */
/*   Updated: 2017/12/07 22:58:16 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	countwords(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c)
			j++;
		while (s[i] != c && s[i])
			i++;
	}
	return (j);
}

static char	**putstring(char **split, char const *s, char c)
{
	int i;
	int x;
	int y;

	x = 0;
	i = 0;
	while (s[i])
	{
		y = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			split[x][y] = s[i];
			i++;
			y++;
		}
		if (y > 0)
			split[x][y] = 0;
		if (s[i] == 0)
			split[x] = 0;
		x++;
	}
	return (split);
}

static void	malloc_split(char **split, char const *s, char c)
{
	int n;
	int i;
	int x;

	i = 0;
	x = 0;
	while (s[i])
	{
		n = 0;
		while (s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			n++;
			i++;
		}
		if (n > 0)
			split[x] = (char*)malloc(sizeof(char) * (n + 1));
		x++;
	}
}

char		**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		n;

	if (s == NULL || *s == 0)
		return (NULL);
	n = countwords(s, c);
	split = (char**)malloc(sizeof(char*) * (n + 1));
	if (split == NULL)
		return (NULL);
	malloc_split(split, s, c);
	putstring(split, s, c);
	return (split);
}
