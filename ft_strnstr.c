/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 21:45:14 by ssong             #+#    #+#             */
/*   Updated: 2017/12/06 18:11:59 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, int n)
{
	int i;
	int j;
	int c;

	i = 0;
	c = 0;
	if (little[i] == 0)
		return ((char*)big);
	while (big[c] && (n - c) > 0)
	{
		i = 0;
		j = c;
		while (big[j] == little[i] && (n - j - 2) > 0)
		{
			i++;
			j++;
		}
		if (little[i] == 0)
			return ((char*)(big + c));
		c++;
	}
	if (big == little)
		return ((char*)(big));
	return (0);
}
