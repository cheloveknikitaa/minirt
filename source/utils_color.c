/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:12:10 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/16 19:15:43 by caugusta         ###   ########.fr       */
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
	double	diffuse;
	int		i;

	i = 0;
	mint = MAX_DIST;
	while (i < 2)
	{
		t = sphIntersect(ro, rd, g_scene.sphere[i].ra,
				g_scene.sphere[i].center);
		if ((t.x > 0.0 && t.x < mint) || (t.y > 0.0 && t.y < mint))
		{
			mint = min(t.x, t.y);
			diffuse = sphdiffuse(ro, rd, mint, i);
			// specular = sphspecular(ro, rd, t, i);
			g_scene.mlx.color = vec3_mulS(g_scene.sphere[i].color, diffuse);
		}
		// t.x = plaIntersect(rd, rd, g_scene.plane);
		// if (t.x > 0.0 && t.x < mint.x)
		// {
		// 	mint = t;
		// 	n = g_scene.plane.ro;
		// 	diffuse = vec3_dot(vec3_mulS(vec3_norm(g_scene.light.ro),
		// 				-g_scene.light.power), n);
		// 	return (vec3_mulS(g_scene.plane.color, diffuse * 0.004));
		// }
		i++;
	}
	if (mint < MAX_DIST)
		return (g_scene.mlx.color);
	return (new_vec3(0, 0, 0));
}
