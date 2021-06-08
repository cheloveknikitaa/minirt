/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:54:45 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/08 17:09:40 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec2	sphIntersect(t_vec3 ro, t_vec3 rd, float ra, t_vec3 center)
{
	float	b;
	float	c;
	float	h;
	t_vec3	oc;

	oc = vec3_sub(ro, center);
	b = vec3_dot(oc, rd);
	c = vec3_dot(oc, oc) - ra * ra;
	h = b * b - c;
	if (h < 0.0)
		return (new_vec2(-1.0, -1.0));
	h = sqrt(h);
	return (new_vec2((-b - h), (-b + h)));
}

// float	sphresult(t_vec3 ro, t_vec3 rd, int i, t_vec2 t)
// {
// 	t_vec3	n;
// 	t_vec3	lightDir;
// 	float	spec;
// 	t_vec3	specular;
// 	t_vec3	reflectDir;

// 	n = vec3_norm(vec3_sub(vec3_add(ro, vec3_mulS(rd, t.x * 0.98)),
// 				g_scene.sphere[i].center));
// 	lightDir = vec3_sub(g_scene.light.ro, g_scene.sphere[i].center);
// 	diffuse = max(vec3_dot(vec3_mulS(vec3_norm(lightDir),
// 					g_scene.light.power), n), 0.0);
// 	g_scene.mlx.color = mix_color(mix_color(g_scene.sphere[i].color,
// 				g_scene.light.color), g_scene.alight.color);
// }
