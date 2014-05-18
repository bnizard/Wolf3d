/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnizard <bnizard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 16:25:52 by bnizard           #+#    #+#             */
/*   Updated: 2014/05/16 16:25:54 by bnizard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "math.h"

float	ft_modulo(float angle)
{
	while (angle >= (2 * M_PI) || angle <= 0)
	{
		if (angle >= (2 * M_PI))
			angle = angle - 2 * M_PI;
		else
			angle = angle + 2 * M_PI;
	}
	return (angle);
}

float	convert_in_radian(float angle)
{
	return (angle = M_PI * angle / 180);
}
