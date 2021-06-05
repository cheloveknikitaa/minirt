/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:12:10 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/05 22:15:21 by caugusta         ###   ########.fr       */
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
	t_vec3	n;
	float	diffuse;
	int		i;

	i = 0;
	while (i < 0)
	{
		t = sphIntersect(rd, rd, g_scene.sphere[i].ra,
				g_scene.sphere[i].center);
		if (t.x > 0.0)
		{
			n = vec3_norm(vec3_sub(vec3_add(ro, vec3_mulS(rd, t.x)),
						g_scene.sphere[i].center));
			diffuse = vec3_dot(vec3_mulS(vec3_norm(g_scene.light.ro), -0.9), n);
			return (vec3_mulS(g_scene.sphere[i].color, diffuse * 0.0040));
		}
		t = 
		i++;
	}
	return (new_vec3(0, 0, 0));
}
