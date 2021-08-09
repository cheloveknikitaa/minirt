/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 21:02:14 by caugusta          #+#    #+#             */
/*   Updated: 2021/07/05 09:45:30 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	cykcalc(t_vec3 ba, t_vec3 oc, t_cylinder *cy, t_vec3 rd)
{
	cy->k2 = vec3_dot(ba, ba) - vec3_dot(ba, rd) * vec3_dot(ba, rd);
	cy->k1 = vec3_dot(ba, ba) * vec3_dot(oc, rd) - vec3_dot(ba, oc) * \
		vec3_dot(ba, rd);
	cy->k0 = vec3_dot(ba, ba) * vec3_dot(oc, oc) - vec3_dot(ba, oc) * \
		vec3_dot(ba, oc) - cy->ra * cy->ra * vec3_dot(ba, ba);
}

double	idiotizm(double y, t_vec3 ba)
{
	if (y < 0.0)
		y = 0.0;
	else
		y = vec3_dot(ba, ba);
	return (y);
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
