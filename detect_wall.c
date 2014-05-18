/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnizard <bnizard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 15:31:59 by bnizard           #+#    #+#             */
/*   Updated: 2014/05/15 02:08:55 by bnizard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <mlx.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>

void	detect_color_wall(t_env *e, float x, float y)
{
	if (e->map[(int)y][(int)x] == 1)
	{
		if (x - e->p.pos_px < 0)
			e->color_wall = 0x00AAAA;
		else
			e->color_wall = 0xFCDC12;
	}
	else
	{
		if (y - e->p.pos_py < 0)
			e->color_wall = 0xFF0000;
		else
			e->color_wall = 0x550000;
	}
}

int		detect_player(t_env *e, char c)
{
	int		x;
	int		y;
	int		result;

	y = 0;
	result = 0;
	while (++y < e->map[0][0])
	{
		x = 0;
		while (++x <= e->map[1][0])
		{
			if (e->map[y][x] == 2)
			{
				result++;
				if (c == 'x' && result == 1)
					return (x);
				else if (c == 'y' && result == 1)
					return (y);
			}
		}
	}
	return (0);
}

float	rail(t_env *e, t_ang a)
{
	float	x;
	float	y;
	float	len;

	x = e->p.pos_px;
	y = e->p.pos_py;
	while (e->map[(int)y][(int)x] != 1 && x >= 1.00 && y >= 1.00
		&& y <= e->map[0][0] && x <= e->map[(int)y][0])
	{
		x = x + 0.015 * cos(a.a);
		detect_color_wall(e, x, y);
		y = y - 0.015 * sin(a.a);
	}
	len = sqrt(pow(x - e->p.pos_px, 2) + pow(y - e->p.pos_py, 2));
	return (len * cos(a.a - e->p.angle));
}

void	detect_wall(t_env *e)
{
	t_ang	a;
	int		x;

	x = 0;
	a.min_a = e->p.angle - convert_in_radian(30);
	a.max_a = e->p.angle + convert_in_radian(30);
	a.a = a.max_a;
	while (x < WIDTH)
	{
		a.a = a.a - convert_in_radian(60.00) / WIDTH;
		ft_draw_wall(rail(e, a), x, e);
		x++;
	}
}

void	ft_draw_wall(float len, int x, t_env *e)
{
	int	y;
	int	wall;

	y = HEIGHT / 2;
	wall = HEIGHT / (2 * len);
	while (y > HEIGHT / 2 - wall)
	{
		mlx_put_px_img(e, x, y, e->color_wall);
		y--;
	}
	y = HEIGHT / 2;
	while (y < HEIGHT / 2 + wall)
	{
		mlx_put_px_img(e, x, y, e->color_wall);
		y++;
	}
}
