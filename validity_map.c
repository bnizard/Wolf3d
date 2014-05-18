/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnizard <bnizard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 20:10:10 by bnizard           #+#    #+#             */
/*   Updated: 2014/05/18 19:01:59 by bnizard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <unistd.h>
#include <fcntl.h>

int		check_file_char(char *file)
{
	int		fd;
	int		i;
	char	*s;

	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &s) > 0)
	{
		i = 0;
		while (s[i])
		{
			if (s[i] != '0' && s[i] != '1' && s[i] != '2' && s[i] != ' '
					&& s[i] != '\0')
			{
				close(fd);
				return (-1);
			}
			i++;
		}
	}
	close(fd);
	return (0);
}

int		check_nb_char_in_line(char *file)
{
	int		fd;
	int		nb;
	int		i;
	char	*s;

	nb = 0;
	fd = open(file, O_RDONLY);
	get_next_line(fd, &s);
	while (s[nb])
		nb++;
	while (get_next_line(fd, &s) > 0)
	{
		i = 0;
		while (s[i])
			i++;
		if (nb != i)
		{
			close(fd);
			return (-1);
		}
	}
	close(fd);
	return (0);
}

int		check_start_position(char *file)
{
	int		fd;
	int		i;
	int		result;
	char	*s;

	result = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &s) > 0)
	{
		i = 0;
		while (s[i])
		{
			if (s[i] == '2')
				result++;
			i++;
		}
	}
	close(fd);
	if (result != 1)
		return (-1);
	return (0);
}

int		check_wall_in_border(int **map)
{
	int		x;
	int		y;
	int		error;

	y = 1;
	error = 0;
	while (y <= map[0][0])
	{
		x = 1;
		while (x < map[y][0])
		{
			if ((y == 1 || y == map[0][0]) && map[y][x] != 1)
				error++;
			else if (map[y][1] != 1 || map[y][map[y][0]] != 1)
				error++;
			x++;
		}
		y++;
	}
	if (error > 0 || y < 3)
	{
		write(1, "Pls put in all around the map a wall block.\n", 45);
		return (-1);
	}
	return (0);
}

int		check_validity_map(char *file)
{
	if (check_file_char(file) == -1)
	{
		write(1, "Pls use only the following characters : 0, 1, 2.\n", 50);
		write(1, "0 : grass block\n1 : wall block\n2 : start position.\n", 53);
		return (-1);
	}
	if (check_nb_char_in_line(file) == -1)
	{
		write(1, "Pls insert the same number of character in each line.\n", 54);
		return (-1);
	}
	if (check_start_position(file) == -1)
	{
		write(1, "Pls insert only one start position in the map.\n", 48);
		return (-1);
	}
	return (0);
}
