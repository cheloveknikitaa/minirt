/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec3_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:43:22 by caugusta          #+#    #+#             */
/*   Updated: 2021/08/10 18:47:57 by caugusta         ###   ########.fr       */
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
	t_vec3	vec;

	vec.x = ft_atof(line);
	if (**line == ',')
	{
		*line = *line + 1;
		if ((**line >= '0' && **line <= '9') || **line == '-' || **line == '+')
			vec.y = ft_atof(line);
		else
			exit_err(5);
	}
	if (**line == ',')
	{
		*line = *line + 1;
		if ((**line >= '0' && **line <= '9') || **line == '-' || **line == '+')
			vec.z = ft_atof(line);
		else
			exit_err(5);
	}
	else
		exit_err(5);
	return (vec);
}

t_vec3	pars_vec3_color(char **line)
{
	t_vec3	vec;

	vec.x = ft_atof(line);
	if (**line == ',')
	{
		*line = *line + 1;
		if ((**line >= '0' && **line <= '9') || **line == '-' || **line == '+')
			vec.y = ft_atof(line);
		else
			exit_err(2);
	}
	if (**line == ',')
	{
		*line = *line + 1;
		if ((**line >= '0' && **line <= '9') || **line == '-' || **line == '+')
			vec.z = ft_atof(line);
		else
			exit_err(2);
	}
	else
		exit_err(2);
	check_pars_vec3(vec.x, vec.y, vec.z, 1);
	return (vec);
}

t_vec3	pars_vec3_norm(char **line)
{
	t_vec3	vec;

	vec.x = ft_atof(line);
	if (**line == ',')
	{
		*line = *line + 1;
		if ((**line >= '0' && **line <= '9') || **line == '-' || **line == '+')
			vec.y = ft_atof(line);
		else
			exit_err(4);
	}
	if (**line == ',')
	{
		*line = *line + 1;
		if ((**line >= '0' && **line <= '9') || **line == '-' || **line == '+')
			vec.z = ft_atof(line);
		else
			exit_err(4);
	}
	else
		exit_err(4);
	check_pars_vec3(vec.x, vec.y, vec.z, 2);
	return (vec);
}

void	check_pars_vec3(double x, double y, double z, int i)
{
	if (i == 1)
	{
		if (x > 255.0 || y > 255.0 || z > 255.0)
			exit_err(2);
	}
	if (i == 2)
	{
		if (x * x + y * y + z * z != 1.0)
			exit_err(4);
	}
}
