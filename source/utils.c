/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 21:02:14 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/26 23:52:10 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	ft_atof(char **line)
{
	double	n;
	int		i;
	double	j;
	int		m;

	i = 0;
	n = 0.0;
	j = 0;
	m = 1;
	while ((line[0][i] >= 9 && line[0][i] <= 13) || line[0][i] == ' ')
		i++;
	if (line[0][i] == '-' || line[0][i] == '+')
	{
		if (line[0][i] == '-')
			m = -m;
		i++;
	}
	while (line[0][i] >= '0' && line[0][i] <= '9')
	{
		j = (j * 10) + (line[0][i] - '0');
		i++;
	}
	n = ft_atof2(line, i);
	return ((j + n) * m);
}

double	ft_atof2(char **line, int i)
{
	double	n;
	int		j;
	int		k;

	n = 0;
	k = 10;
	if (line[0][i] == '.')
	{
		i++;
		j = i;
		while (line[0][i] >= '0' && line[0][i] <= '9')
		{
			n = n + ((double)(line[0][i] - '0') / k);
			k *= 10;
			i++;
		}
		if (j == i)
			exit_err(3);
	}
	else
		n = 0.0;
	*line = *line + i;
	return (n);
}
