/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita <nikita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 01:21:31 by caugusta          #+#    #+#             */
/*   Updated: 2021/07/31 21:54:01 by nikita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	max(double a, double b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

double	min(double a, double b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

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

t_vec3	rgb_to_xyz(t_vec3 color)
{
	t_vec3	tmp;

	color = vec3_mulS(color, 1 / 255.0);
	if (color.x > 0.04045)
		color.x = pow(((color.x + 0.055) / 1.055), 2.4);
	else
		color.x /= 12.92;
	if (color.y > 0.04045)
		color.y = pow(((color.y + 0.055) / 1.055), 2.4);
	else
		color.y /= 12.92;
	if (color.z > 0.04045)
		color.z = pow(((color.z + 0.055) / 1.055), 2.4);
	else
		color.z /= 12.92;
	return (color);
}
