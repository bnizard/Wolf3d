/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnizard <bnizard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/05 15:44:28 by bnizard           #+#    #+#             */
/*   Updated: 2014/05/05 15:48:26 by bnizard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*src_tmp;
	char		*dest_tmp;

	src_tmp = src;
	dest_tmp = dest;
	i = 0;
	while (i < n)
	{
		dest_tmp[i] = src_tmp[i];
		i++;
	}
	return (dest);
}
