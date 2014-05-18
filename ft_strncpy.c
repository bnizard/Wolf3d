/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnizard <bnizard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 06:39:42 by bnizard           #+#    #+#             */
/*   Updated: 2014/05/06 16:19:59 by bnizard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <unistd.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		if (src[i] == '\0')
		{
			while (i < n)
			{
				dest[i] = '\0';
				i++;
			}
		}
		i++;
	}
	return (dest);
}
