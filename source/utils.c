/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 21:02:14 by caugusta          #+#    #+#             */
/*   Updated: 2021/08/09 19:48:39 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
