/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:54:45 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/08 22:52:38 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec2	sphIntersect(t_vec3 ro, t_vec3 rd, double ra, t_vec3 center)
{
	double	b;
	double	c;
	double	h;
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

// double	sphresult(t_vec3 ro, t_vec3 rd, int i, t_vec2 t)
// {
// 	t_vec3	n;
// 	t_vec3	lightDir;
// 	double	spec;
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

t_vec3	sphdiffuse(t_vec3 ro, t_vec3 rd, t_vec2 t, int i)
{
	t_vec3	n;
	t_vec3	lightDir;
	t_vec3	diffuse;

	n = vec3_norm(vec3_sub(vec3_add(ro, vec3_mulS(rd, t.x * 0.99)),
				g_scene.sphere[i].center));
	lightDir = vec3_sub(g_scene.light.ro, g_scene.sphere[i].center);
	diffuse.x = max(vec3_dot(vec3_mulS(vec3_norm(lightDir),
					g_scene.light.power), n), 0.0);
	diffuse.y = diffuse.x * 0.0002;
	diffuse.z = diffuse.x * 0.0007;
	diffuse.x = diffuse.x * 0.0005;
	return (diffuse);
}

t_vec3	sphspecular(t_vec3 ro, t_vec3 rd, t_vec2 t, int i)
{
	t_vec3	n;
	double	spec;
	t_vec3	specular;
	t_vec3	viewdir;
	t_vec3	reflectdir;

	n = vec3_norm(vec3_sub(vec3_add(ro, vec3_mulS(rd, t.x * 0.99)),
				g_scene.sphere[i].center));
	viewdir = vec3_norm(vec3_sub(ro, g_scene.sphere[i].center));
	reflectdir = vec3_norm(vec3_reflect(vec3_mulS(vec3_sub(g_scene.light.ro,
						g_scene.sphere[i].center), -1), n));
	spec = powf(max(vec3_dot(viewdir, reflectdir), 0.0), SPEC_STRNG) * 0.000007;
	specular = vec3_mulS(g_scene.light.color, spec);
	return (specular);
}
