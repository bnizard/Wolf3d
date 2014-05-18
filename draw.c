/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnizard <bnizard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/05 16:54:20 by bnizard           #+#    #+#             */
/*   Updated: 2014/05/09 17:57:30 by bnizard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <mlx.h>
#include "stdio.h"

void	mlx_put_px_img(t_env *e, int x, int y, int color)
{
	if (x >= 0 && x <= e->width && y >= 0 && y <= e->height)
		ft_memcpy(&(e->data[y * e->width * 4 + x * 4]), &color, 4);
}

void	draw_sky(t_env *e)
{
	int		x;
	int		y;

	x = 0;
	while (x < e->width)
	{
		y = 0;
		while (y < (e->height / 2))
		{
			mlx_put_px_img(e, x, y, e->color_sky);
			y++;
		}
		x++;
	}
}

void	draw_ground(t_env *e)
{
	int		x;
	int		y;

	x = 0;
	while (x < e->width)
	{
		y = e->height / 2;
		while (y < e->height)
		{
			mlx_put_px_img(e, x, y, e->color_ground);
			y++;
		}
		x++;
	}
}

int		draw(t_env *e)
{
	draw_sky(e);
	draw_ground(e);
	detect_wall(e);
	return (0);
}

int		expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}
