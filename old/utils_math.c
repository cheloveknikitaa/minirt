/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 01:21:31 by caugusta          #+#    #+#             */
/*   Updated: 2021/08/09 20:02:39 by caugusta         ###   ########.fr       */
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

t_vec2	solve_quadratic(double a, double b, double c)
{
	double	d;
	double	q;
	t_vec2	t;

	d = b * b - 4 * a * c;
	if (d < 0.0)
		return (new_vec2(-1.0, -1.0));
	else if (d == 0.0)
		return (new_vec2(-0.5 * b / a, -0.5 * b / a));
	else
	{
		if (b > 0)
			q = -0.5 * (b + sqrt(d));
		else
			q = -0.5 * (b - sqrt(d));
		t.x = q / a;
		t.y = c / q;
	}
	if (t.x > t.y)
	{
		q = t.y;
		t.y = t.x;
		t.x = q;
	}
	return (t);
}
