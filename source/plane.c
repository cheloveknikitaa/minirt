/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:55:03 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/16 21:12:10 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	plaIntersect(t_vec3 ro, t_vec3 rd, t_plane pl)
{
	double	d;

	d = -(pl.n.x * pl.ro.x) - (pl.n.y * \
		pl.ro.y) - (pl.n.z * pl.ro.z);
	return (-(vec3_dot(ro, pl.n) + d) / vec3_dot(rd, pl.n));
}

double	pladiffuse(t_vec3 ro, t_vec3 rd, double t, int j)
{
	t_vec3	p;
	t_vec3	n;
	t_vec3	lightDir;
	t_vec3	r;
	double	i;

	i = g_scene.alight.power;
	p = vec3_add(ro, vec3_mulS(rd, t - 0.001));
	n = g_scene.plane.n;
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
