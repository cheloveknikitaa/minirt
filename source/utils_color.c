/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:12:10 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/17 17:58:58 by caugusta         ###   ########.fr       */
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

t_vec3	ray_color(t_vec3 ro, t_vec3 rd)
{
	t_vec2	t;
	double	mint;
	t_vec3	p;
	t_vec3	n;
	int		i;

	i = 0;
	mint = DBL_MAX;
	while (i < 2)
	{
		t = sphIntersect(ro, rd, g_scene.sphere[i].ra,
				g_scene.sphere[i].center);
		if ((t.x > 0.0 && t.x < mint) || (t.y > 0.0 && t.y < mint))
		{
			mint = min(t.x, t.y);
			p = vec3_add(ro, vec3_mulS(rd, mint - 0.001));
			n = vec3_norm(vec3_sub(p, g_scene.sphere[i].center));
			g_scene.mlx.color = g_scene.sphere[i].color;
		}
		t.x = plaIntersect(ro, rd, &g_scene.plane);
		if (t.x > 0.0 && t.x < mint)
		{
			mint = t.x;
			p = vec3_add(ro, vec3_mulS(rd, mint - 0.001));
			n = g_scene.plane.n;
			g_scene.mlx.color = g_scene.plane.color;
			break ;
		}
		i++;
	}
	if (mint < DBL_MAX)
		return (vec3_mulS(g_scene.mlx.color, diffuse(p, n, rd)));
	return (new_vec3(1, 1, 1));
}

int	shadow(t_vec3 ro, t_vec3 rd)
{
	t_vec2	t;
	double	mint;
	int		i;

	i = 0;
	mint = DBL_MAX;
	while (i < 2)
	{
		t = sphIntersect(ro, rd, g_scene.sphere[i].ra,
				g_scene.sphere[i].center);
		if ((t.x > 0.0 && t.x < mint) || (t.y > 0.0 && t.y < mint))
		{
			mint = min(t.x, t.y);
		}
		t.x = plaIntersect(ro, rd, &g_scene.plane);
		if (t.x > 0.0 && t.x < mint)
		{
			mint = t.x;
		}
		i++;
	}
	if (mint < DBL_MAX)
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
		{
			i *= 1.0001;
			return (i);
		}
	}
	i += (g_scene.light.power * max(vec3_dot(n, lightDir), 0.0)) / \
		(vec3_lenght(n) * vec3_lenght(lightDir));
	// r = vec3_sub(vec3_mulS(vec3_mulS(n, 2), vec3_dot(n, lightDir)), lightDir);
	// rd = vec3_mulS(rd, -1);
	// i += (g_scene.light.power * powf(max(vec3_dot(r, rd) / \
	// 	(vec3_lenght(r) * vec3_lenght(rd)), 0.0), SPEC_STRNG));
	return (min(i, 1.0));
}
