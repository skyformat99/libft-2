/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 20:01:53 by ssong             #+#    #+#             */
/*   Updated: 2017/12/09 13:56:25 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

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
		if (s[i] && s[i] != c)
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
		while (s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			split[x][y] = s[i];
			i++;
			y++;
		}
		if (y > 0)
		{
			split[x][y] = 0;
			x++;
		}
	}
	split[x] = 0;
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
		{
			split[x] = (char*)malloc(sizeof(char) * (n + 1));
			x++;
		}
	}
}

char		**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		n;

	if (s == NULL)
		return (NULL);
	n = countwords(s, c);
	split = (char**)malloc(sizeof(char*) * (n + 1));
	if (split == NULL)
		return (NULL);
	if (s[0])
	{
		malloc_split(split, s, c);
		putstring(split, s, c);
	}
	else if (s[0] == 0)
		split[0] = NULL;
	return (split);
}
