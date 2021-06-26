/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 01:21:31 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/26 22:19:27 by caugusta         ###   ########.fr       */
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

t_vec3	get_ray(int i, int j)
{
	t_cam	cam;
	t_vec3	ray;
	double	u;
	double	v;

	u = (double)i / (g_scene.width - 1);
	v = (g_scene.height - (double)j - 1) / (g_scene.height - 1);
	cam = g_scene.cam;
	ray = vec3_add(cam.lower_left_corner,
			vec3_add(vec3_mulS(cam.horizontal, u),
				vec3_sub(vec3_mulS(cam.vertical, v), cam.ro)));
	return (vec3_norm(ray));
}
