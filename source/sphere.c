/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:54:45 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/16 20:16:12 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec2	sphIntersect(t_vec3 ro, t_vec3 rd, double ra, t_vec3 center)
{
	double	a;
	double	b;
	double	c;
	double	h;
	t_vec3	oc;

	oc = vec3_sub(ro, center);
	a = vec3_dot(rd, rd);
	b = 2 * vec3_dot(oc, rd);
	c = vec3_dot(oc, oc) - ra * ra;
	h = b * b - 4 * a * c;
	if (h < 0.0)
		return (new_vec2(-1.0, -1.0));
	h = sqrt(h);
	return (new_vec2((-b + h) / (2 * a), (-b - h) / (2 * a)));
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

double	sphdiffuse(t_vec3 ro, t_vec3 rd, double t, int j)
{
	t_vec3	p;
	t_vec3	n;
	t_vec3	lightDir;
	t_vec3	r;
	double	i;

	i = g_scene.alight.power;
	p = vec3_add(ro, vec3_mulS(rd, t - 0.001));
	n = vec3_sub(p, g_scene.sphere[j].center);
	n = vec3_div(n, vec3_lenght(n));
	lightDir = vec3_sub(g_scene.light.ro, p);
	i += (g_scene.light.power * max(vec3_dot(n, lightDir), 0.0)) / \
		(vec3_lenght(n) * vec3_lenght(lightDir));
	r = vec3_sub(vec3_mulS(vec3_mulS(n, 2), vec3_dot(n, lightDir)), lightDir);
	rd = vec3_mulS(rd, -1);
	if (vec3_dot(n, lightDir) > 0)
	{
		if (shadow(p, lightDir) == 1)
			i *= 0.3;
	}
	// i += (g_scene.light.power * powf(max(vec3_dot(r, rd) / \
	// 	(vec3_lenght(r) * vec3_lenght(rd)), 0.0), SPEC_STRNG));
	return (min(i, 1.0));
}
