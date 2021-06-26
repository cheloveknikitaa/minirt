/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec3_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:43:22 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/26 23:51:26 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	vec3_cross(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = (a.y * b.z) - (a.z * b.y);
	result.y = (a.z * b.x) - (a.x * b.z);
	result.z = (a.x * b.y) - (a.y * b.x);
	return (result);
}

t_vec3	pars_vec3(char **line)
{
	double	x;
	double	y;
	double	z;

	x = ft_atof(line);
	if (**line == ',')
	{
		*line = *line + 1;
		y = ft_atof(line);
	}
	else
		exit_err(5);
	if (**line == ',')
	{
		*line = *line + 1;
		z = ft_atof(line);
	}
	else
		exit_err(5);
	return (new_vec3(x, y, z));
}

t_vec3	pars_vec3_color(char **line)
{
	double	x;
	double	y;
	double	z;

	x = ft_atof(line);
	if (**line == ',')
	{
		*line = *line + 1;
		y = ft_atof(line);
	}
	else
		exit_err(2);
	if (**line == ',')
	{
		*line = *line + 1;
		z = ft_atof(line);
	}
	else
		exit_err(2);
	if (x > 255.0 || y > 255.0 || z > 255.0)
		exit_err(2);
	return (new_vec3(x, y, z));
}

t_vec3	pars_vec3_norm(char **line)
{
	double	x;
	double	y;
	double	z;

	x = ft_atof(line);
	if (**line == ',')
	{
		*line = *line + 1;
		y = ft_atof(line);
	}
	else
		exit_err(4);
	if (**line == ',')
	{
		*line = *line + 1;
		z = ft_atof(line);
	}
	else
		exit_err(4);
	if (x + y + z > 1)
		exit_err(4);
	return (new_vec3(x, y, z));
}
