/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:12:10 by caugusta          #+#    #+#             */
/*   Updated: 2021/08/10 17:44:10 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	write_color(t_data *scene, t_vec3 ray)
{
	int	r;
	int	g;
	int	b;

	r = 255.999 * ray.x;
	g = 255.999 * ray.y;
	b = 255.999 * ray.z;
	scene->color.x = r * 256 * 256;
	scene->color.y = g * 256;
	scene->color.z = b;
	scene->int_color = scene->color.x + scene->color.y + scene->color.z;
}

t_vec3	ray_color(t_vec3 ro, t_vec3 rd, int i)
{
	double	t;
	double	mint;
	t_vec3	p;
	t_vec3	n;

	mint = DBL_MAX;
	while (i < g_scene.sp || i < g_scene.pl || i < g_scene.cy || i < g_scene.co)
	{
		t = sphIntersect(ro, rd, &g_scene.sphere[i]);
		if (t > 0.0 && t < mint)
			g_scene.mlx.color = spcolor(&mint, &p, &n, g_scene.sphere[i]);
		t = plaIntersect(ro, rd, &g_scene.plane[i]);
		if (t > 0.0 && t < mint)
			g_scene.mlx.color = plcolor(&mint, &p, &n, g_scene.plane[i]);
		t = cyintersect(ro, rd, &g_scene.cylinder[i]);
		if (t > 0.0 && t < mint)
			g_scene.mlx.color = cycolor(&mint, &p, &n, g_scene.cylinder[i]);
		t = cointersect(ro, rd, &g_scene.cone[i]);
		if (t > 0.0 && t < mint)
			g_scene.mlx.color = cocolor(&mint, &p, &n, g_scene.cone[i]);
		i++;
	}
	if (mint < DBL_MAX)
		return (vec3_mulS(g_scene.mlx.color, diffuse(p, n, rd)));
	return (new_vec3(0, 0, 0));
}

int	shadow(t_vec3 ro, t_vec3 rd)
{
	double	t;
	double	mint;
	int		i;

	i = 0;
	mint = 1.0;
	while (i < g_scene.sp || i < g_scene.pl || i < g_scene.cy || i < g_scene.co)
	{
		t = sphIntersect(ro, rd, &g_scene.sphere[i]);
		if (t > DBL_EPSILON && t < mint)
			mint = t;
		t = plaIntersect(ro, rd, &g_scene.plane[i]);
		if (t > DBL_EPSILON && t < mint)
			mint = t;
		t = cyintersect(ro, rd, &g_scene.cylinder[i]);
		if (t > DBL_EPSILON && t < mint)
			mint = t;
		t = cointersect(ro, rd, &g_scene.cone[i]);
		if (t > DBL_EPSILON && t < mint)
			mint = t;
		i++;
	}
	if (mint < 1.0)
		return (1);
	return (0);
}

double	diffuse(t_vec3 p, t_vec3 n, t_vec3 rd)
{
	t_vec3	lightDir;
	t_vec3	r;
	double	i;

	i = g_scene.alight.power;
	lightDir = vec3_sub(g_scene.light.ro, p);
	if (vec3_dot(n, lightDir) > 0)
	{
		if (shadow(p, lightDir) == 1)
			return (min(i, 1.0));
	}
	i += (g_scene.light.power * max(vec3_dot(n, lightDir), 0.0)) / \
		(vec3_lenght(n) * vec3_lenght(lightDir));
	r = vec3_sub(vec3_mulS(vec3_mulS(n, 2), vec3_dot(n, lightDir)), lightDir);
	rd = vec3_mulS(rd, -1);
	i += (g_scene.light.power * pow(max(vec3_dot(r, rd) / \
		(vec3_lenght(r) * vec3_lenght(rd)), 0.0), SPEC_STRNG));
	return (min(i, 1.0));
}

void	mix_color_light(t_light *light, t_alight *alight)
{
	light->color = vec3_add(light->color, alight->color);
	if (light->color.x > 255.0)
		light->color.x = 255.0;
	if (light->color.x < 0)
		light->color.x = 0.0;
	if (light->color.y > 255.0)
		light->color.y = 255.0;
	if (light->color.y < 0)
		light->color.y = 0.0;
	if (light->color.z > 255.0)
		light->color.z = 255.0;
	if (light->color.z < 0)
		light->color.z = 0.0;
	alight->color = vec3_mulS(alight->color, 1 / 255);
}
