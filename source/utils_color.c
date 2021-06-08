/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:12:10 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/08 06:32:27 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	 write_color(t_data *scene, t_vec3 ray)
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
	t_vec2	mint;
	t_vec3	n;
	float	diffuse;
	int		i;

	i = 0;
	mint = new_vec2(MAX_DIST, MAX_DIST);
	while (i < 2)
	{
		t = sphIntersect(ro, rd, g_scene.sphere[i].ra,
				g_scene.sphere[i].center);
		if (t.x > 0.0 && t.x < mint.x)
		{
			mint = t;
			n = vec3_norm(vec3_sub(vec3_add(ro, vec3_mulS(rd, t.x * 0.98)),
						g_scene.sphere[i].center));
			diffuse = vec3_dot(vec3_mulS(vec3_norm(g_scene.light.ro),
						-g_scene.light.power), n);
			g_scene.mlx.color = mix_color(g_scene.sphere[i].color, g_scene.light.color);
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
	if (mint.x < MAX_DIST)
		return (vec3_mulS(g_scene.mlx.color, diffuse * 0.003));
	return (new_vec3(0, 0, 0));
}

t_vec3	mix_color(t_vec3 color1, t_vec3 color2)
{
	t_vec3	color1_mko;
	t_vec3	color2_mko;
	t_vec3	mix;

	color1_mko = rgb_to_Yxy(color1);
	color2_mko = rgb_to_Yxy(color2);
	mix.x = (color1_mko.x * color1_mko.z / color1_mko.y + \
			color2_mko.x * color2_mko.z / color2_mko.y) / \
			(color1_mko.z / color1_mko.y + color2_mko.z / color2_mko.y);
	mix.y = (color1_mko.y * color1_mko.z / color1_mko.y + \
			color2_mko.y * color2_mko.z / color2_mko.y) / \
			(color1_mko.z / color1_mko.y + color2_mko.z / color2_mko.y);
	mix.z = color1_mko.z + color2_mko.z;
	mix = Yxy_to_rgb(mix);
	return (mix);
}

t_vec3	rgb_to_Yxy(t_vec3 color)
{
	t_vec3	tmp;

	color = vec3_mulS(color, 1 / 255.0);
	if (color.x > 0.04045)
		color.x = powf(((color.x + 0.055) / 1.055), 2.4);
	else
		color.x /= 12.92;
	if (color.y > 0.04045)
		color.y = powf(((color.y + 0.055) / 1.055), 2.4);
	else
		color.y /= 12.92;
	if (color.z > 0.04045)
		color.z = powf(((color.z + 0.055) / 1.055), 2.4);
	else
		color.z /= 12.92;
	color = vec3_mulS(color, 100.0);
	tmp.x = color.x * 0.4124 + color.y * 0.3576 + color.z * 0.1805;
	tmp.y = color.x * 0.2126 + color.y * 0.7152 + color.z * 0.0722;
	tmp.z = color.x * 0.0193 + color.y * 0.1192 + color.z * 0.9505;
	color = tmp;
	// printf("X = %f Y = %f, Z = %f\n", color.x, color.y, color.z);
	tmp.z = tmp.y;
	tmp.x = color.x / (color.x + color.y + color.z);
	tmp.y = color.y / (color.x + color.y + color.z);
	// printf("x= %f y = %f, Y = %f\n", tmp.x, tmp.y, tmp.z);
	return (tmp);
}

t_vec3	Yxy_to_rgb(t_vec3 color)
{
	t_vec3	tmp;

	tmp.x = color.x * (color.z / color.y);
	tmp.y = color.z;
	tmp.z = (1 - color.x - color.y) * (color.z / color.y);
	color = vec3_mulS(tmp, 1 / 100.0);
	tmp.x = color.x * 3.2406 + color.y * -1.5372 + color.z * -0.4986;
	tmp.y = color.x * -0.9689 + color.y * 1.8758 + color.z * 0.0415;
	tmp.z = color.x * 0.0557 + color.y * -0.2040 + color.z * 1.0570;
	if (tmp.x > 0.0031308)
		color.x = 1.055 * powf(tmp.x, 1 / 2.4) - 0.055;
	else
		color.x = tmp.x * 12.92;
	if (tmp.y > 0.0031308)
		color.y = 1.055 * powf(tmp.y, 1 / 2.4) - 0.055;
	else
		color.y = tmp.y * 12.92;
	if (tmp.z > 0.0031308)
		color.z = 1.055 * powf(tmp.z, 1 / 2.4) - 0.055;
	else
		color.z = tmp.z * 12.92;
	color = vec3_mulS(color, 255.0);
	// printf("r = %f g = %f, b = %f\n", color.x, color.y, color.z);
	return (color);
}
