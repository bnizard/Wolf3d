/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnizard <bnizard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 19:35:40 by bnizard           #+#    #+#             */
/*   Updated: 2014/05/06 17:36:21 by bnizard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		result;
	int		negative;

	i = 0;
	negative = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		negative = 1;
		i++;
	}
	while (ft_isdigit(str[i]) != 0)
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (negative == 1)
		result = -result;
	return (result);
}
