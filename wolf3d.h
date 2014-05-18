/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnizard <bnizard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/05 15:00:29 by bnizard           #+#    #+#             */
/*   Updated: 2014/05/14 23:24:08 by bnizard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "structs.h"
# include <stdlib.h>

# define FOV 60
# define P_LEN 32
# define WIDTH 800
# define HEIGHT 600

/*
**		draw.c
*/
void	mlx_put_px_img(t_env *e, int x, int y, int color);
void	draw_sky(t_env *e);
void	draw_ground(t_env *e);
int		draw(t_env *e);
int		expose_hook(t_env *e);

/*
**		stock_map.c
*/
int		count_len(char *s);
int		*fill_map(char **s, int *tab);
int		**stock_map(char *file, int fd);
void	print_map(int **tab);

/*
**		detect_wall.c
*/
void	detect_color_wall(t_env *e, float x, float y);
int		detect_player(t_env *e, char c);
float	rail(t_env *e, t_ang a);
void	detect_wall(t_env *e);
void	ft_draw_wall(float len, int x, t_env *e);

/*
**		validity_map.c
*/
int		check_file_char(char *file);
int		check_nb_char_in_line(char *file);
int		check_start_position(char *file);
int		check_wall_in_border(int **map);
int		check_validity_map(char *file);

/*
**		tools.c
*/
float	ft_modulo(float angle);
float	convert_in_radian(float angle);

/*
**		libft
*/
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_atoi(const char *s);
int		ft_isdigit(int c);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	**ft_strsplit(const char *s, char c);
int		get_next_line(int const fd, char **line);
#endif
