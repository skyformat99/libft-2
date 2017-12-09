/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 21:45:14 by ssong             #+#    #+#             */
/*   Updated: 2017/12/08 16:26:02 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, int n)
{
	int i;

	i = 0;
	if (*little == 0)
		return ((char*)big);
	while (*big && n)
	{
		if (*big == little[i])
			i++;
		else
			i = 0;
		if (little[i] == 0)
			return ((char*)big - i + 1);
		big++;
		n--;
	}
	return (NULL);
}
