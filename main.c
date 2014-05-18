/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnizard <bnizard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/05 14:56:54 by bnizard           #+#    #+#             */
/*   Updated: 2014/05/15 06:03:55 by bnizard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <mlx.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

int		keycode_up_down(int keycode, t_env *e)
{
	float	tmp_x;
	float	tmp_y;

	if (keycode == 65362)
	{
		tmp_x = e->p.pos_px + cos(e->p.angle) * 0.3;
		tmp_y = e->p.pos_py - sin(e->p.angle) * 0.3;
		if (e->map[(int)tmp_y][(int)tmp_x] != 1)
		{
			e->p.pos_px = e->p.pos_px + cos(e->p.angle) * 0.3;
			e->p.pos_py = e->p.pos_py - sin(e->p.angle) * 0.3;
		}
	}
	if (keycode == 65364)
	{
		tmp_x = e->p.pos_px - cos(e->p.angle) * 0.3;
		tmp_y = e->p.pos_py + sin(e->p.angle) * 0.3;
		if (e->map[(int)tmp_y][(int)tmp_x] != 1)
		{
			e->p.pos_px = e->p.pos_px - cos(e->p.angle) * 0.3;
			e->p.pos_py = e->p.pos_py + sin(e->p.angle) * 0.3;
		}
	}
	return (0);
}

int		key_press(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 65361)
		e->p.angle = e->p.angle + 0.1;
	if (keycode == 65363)
		e->p.angle = e->p.angle - 0.1;
	keycode_up_down(keycode, e);
	draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		ft_error(int error)
{
	if (error == 1)
		write(1, "Execute the binary with only one map in argument.\n", 50);
	if (error == 2)
		write(1, "Permission denied on this file.\n", 32);
	return (0);
}

void	init_variables(t_env *e)
{
	e->width = WIDTH;
	e->height = HEIGHT;
	e->color_sky = 0x0000FF;
	e->color_ground = 0x00FF00;
	e->color_wall = 0xFF0000;
	e->p.pos_px = detect_player(e, 'x') + 0.5;
	e->p.pos_py = detect_player(e, 'y') + 0.5;
	e->p.angle = 0;
	e->win = mlx_new_window(e->mlx, e->width, e->height, "wolf3d");
	e->img = mlx_new_image(e->mlx, e->width, e->height);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
}

int		main(int ac, char **av)
{
	t_env	e;
	int		fd;

	if (ac != 2)
		return (ft_error(1));
	else if ((fd = open(av[1], O_RDONLY)) < 0)
		return (ft_error(2));
	else
	{
		if (!(e.mlx = mlx_init()))
			return (0);
		if (check_validity_map(av[1]) == -1)
			return (0);
		e.map = stock_map(av[1], fd);
		if (check_wall_in_border(e.map) == -1)
			return (0);
		close(fd);
		init_variables(&e);
		draw(&e);
		mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
		mlx_hook(e.win, 2, 1, &key_press, &e);
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_loop(e.mlx);
	}
	return (0);
}
