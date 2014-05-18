/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnizard <bnizard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/05 15:01:41 by bnizard           #+#    #+#             */
/*   Updated: 2014/05/09 17:49:09 by bnizard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_ang
{
	float		min_a;
	float		max_a;
	float		a;
}				t_ang;

typedef struct	s_player
{
	float		pos_px;
	float		pos_py;
	float		angle;
}				t_player;

typedef struct	s_env
{
	int			width;
	int			height;
	int			color_sky;
	int			color_ground;
	int			color_wall;
	char		*mlx;
	char		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	int			**map;
	t_player	p;
}				t_env;

#endif
