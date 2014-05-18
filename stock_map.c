/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnizard <bnizard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/07 18:09:27 by bnizard           #+#    #+#             */
/*   Updated: 2014/05/14 20:21:38 by bnizard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int		count_len(char *s)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (s[i])
	{
		if (s[i] <= '9' && s[i] >= '0' && (s[i + 1] == ' ' || s[i + 1] == '\0'))
			result++;
		i++;
	}
	return (result);
}

int		*fill_map(char **s, int *tab)
{
	int		i;
	int		j;
	int		*tmp;

	i = 0;
	j = 1;
	tmp = tab;
	while (s[i])
		tmp[j++] = ft_atoi(s[i++]);
	return (tmp);
}

int		**stock_map(char *file, int fd)
{
	char	*s;
	int		i;
	int		**tab;
	char	**tmp;

	i = 0;
	while (get_next_line(fd, &s) > 0)
		i++;
	if (!(tab = (int **)malloc(sizeof(int *) * (i + 1))))
		return (0);
	close(fd);
	fd = open(file, O_RDONLY);
	tab[0] = (int *)malloc(sizeof(int));
	tab[0][0] = i;
	i = 1;
	while (get_next_line(fd, &s) > 0)
	{
		tab[i] = (int *)malloc(sizeof(int) * (count_len(s) + 1));
		tmp = ft_strsplit(s, ' ');
		tab[i] = fill_map(tmp, tab[i]);
		tab[i++][0] = count_len(s);
	}
	close(fd);
	print_map(tab);
	return (tab);
}

void	print_map(int **tab)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	ft_putnbr(tab[0][0]);
	write(1, "\n", 2);
	while (i <= tab[0][0])
	{
		while (j <= tab[i][0])
		{
			ft_putnbr(tab[i][j]);
			write(1, " ", 1);
			j++;
		}
		j = 0;
		write(1, "\n", 1);
		i++;
	}
}
