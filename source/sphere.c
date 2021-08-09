/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:54:45 by caugusta          #+#    #+#             */
/*   Updated: 2021/08/09 18:20:55 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	sphIntersect(t_vec3 ro, t_vec3 rd, t_sphere	*sp)
{
	double	a;
	double	b;
	double	c;
	double	h;
	t_vec3	oc;

	oc = vec3_sub(ro, sp->center);
	a = vec3_dot(rd, rd);
	b = 2 * vec3_dot(oc, rd);
	c = vec3_dot(oc, oc) - sp->ra * sp->ra;
	h = b * b - 4 * a * c;
	if (h < 0.0)
		return (-1.0);
	h = sqrt(h);
	return (sp_new_normal(sp, new_vec2((-b + h) / (2 * a), (-b - h) / (2 * a)), \
		ro, rd));
}

void	init_sphere(char **line, t_sphere *sphere)
{
	char	*linekeep;

	linekeep = *line;
	*line = *line + 2;
	sphere->center = pars_vec3(line);
	sphere->ra = ft_atof(line);
	if (sphere->ra < 0)
		exit_err(3);
	sphere->color = rgb_to_xyz(pars_vec3_color(line));
	g_scene.sp += 1;
	free (linekeep);
	*line = NULL;
}

double	sp_new_normal(t_sphere *sp, t_vec2 t, t_vec3 ro, t_vec3 rd)
{
	double	where_cam;
	double	where_light;

	where_cam = pow((g_scene.cam.ro.x - sp->center.x), 2.0) + \
		pow((g_scene.cam.ro.y - sp->center.y), 2.0) + \
		pow((g_scene.cam.ro.z - sp->center.z), 2.0);
	where_light = pow((g_scene.light.ro.x - sp->center.x), 2.0) + \
		pow((g_scene.light.ro.y - sp->center.y), 2.0) + \
		pow((g_scene.light.ro.z - sp->center.z), 2.0);
	if (where_light < pow(sp->ra, 2.0))
		return (min(t.x, t.y));
	if (ro.x != g_scene.cam.ro.x && ro.y != g_scene.cam.ro.y && \
		ro.z != g_scene.cam.ro.z)
		return (min(t.x, t.y));
	if (where_cam < pow(sp->ra, 2.0))
		sp->mint = max(t.x, t.y);
	else
		sp->mint = min(t.x, t.y) + 0.01;
	sp->p = vec3_add(ro, vec3_mulS(rd, sp->mint));
	sp->n = vec3_norm(vec3_sub(sp->p, sp->center));
	return (sp->mint);
}

t_vec3	spcolor(double *mint, t_vec3 *p, t_vec3 *n, t_sphere sp)
{
	*mint = sp.mint;
	*p = sp.p;
	*n = sp.n;
	return (sp.color);
}
