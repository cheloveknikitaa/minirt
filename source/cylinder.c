/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:55:43 by caugusta          #+#    #+#             */
/*   Updated: 2021/07/04 14:05:48 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec2	cyintersect(t_vec3 ro, t_vec3 rd, t_cylinder *cy)
{
	double	a[5];
	t_vec2	t;

	cy->oc = vec3_sub(ro, cy->c);
	cy->ca = vec3_mulS(vec3_sub(cy->pb, cy->pa), 1 / cy->height);
	a[0] = 1.0 - vec3_dot(cy->ca, rd);
	a[1] = vec3_dot(cy->oc, rd) - vec3_dot(cy->ca, cy->oc) * \
		vec3_dot(cy->ca, rd);
	a[2] = vec3_dot(cy->oc, cy->oc) - vec3_dot(cy->ca, cy->oc) * \
		vec3_dot(cy->ca, cy->oc) - cy->ra * cy->ra;
	a[3] = a[1] * a[1] - a[0] * a[2];
	if (a[3] < 0.0)
		return (new_vec2(-1.0, -1.0));
	a[3] = sqrtf(a[3]);
	t.x = (-a[1] - a[3]) / a[0];
	t.y = (-a[1] + a[3]) / a[0];
	a[4] = vec3_dot(cy->ca, cy->oc) + t.x * vec3_dot(cy->ca, rd);
	if (fabs(a[4]) < cy->half_h)
		return (new_normal_body(t, cy, rd, a[4]));
	return (new_normal_caps(t, cy, rd, a));
}

t_vec2	new_normal_body(t_vec2 t, t_cylinder *cy, t_vec3 rd, double y)
{
	cy->n = vec3_sub(vec3_add(cy->oc, vec3_mulS(rd, t.x)), \
		vec3_mulS(cy->ca, y));
	return (t);
}

t_vec2	new_normal_caps(t_vec2 t, t_cylinder *cy, t_vec3 rd, double a[5])
{
	double	tp;

	if (a[4] < 0)
		a[4] = -1;
	else if (a[4] > 0)
		a[4] = 1;
	else if (a[4] == 0)
		a[4] = 0;
	tp = (a[5] * cy->half_h - vec3_dot(cy->ca, cy->oc)) / vec3_dot(cy->ca, rd);
	if (fabs(a[1] + a[0] * tp) < a[3])
	{
		cy->n = vec3_mulS(cy->ca, a[4]);
		return (t);
	}
	return (new_vec2(-1.0, -1.0));
}

void	init_cy(char **line, t_cylinder *cylinder)
{
	char	*linekeep;

	linekeep = *line;
	*line = *line + 2;
	cylinder->pa = pars_vec3(line);
	cylinder->nv = pars_vec3_norm(line);
	cylinder->ra = ft_atof(line) / 2;
	cylinder->height = ft_atof(line);
	cylinder->color = rgb_to_xyz(pars_vec3_color(line));
	cylinder->pb = vec3_add(vec3_mulS(cylinder->nv, cylinder->height), \
		cylinder->pa);
	cylinder->c = vec3_mulS(vec3_add(cylinder->pa, cylinder->pb), 0.5);
	cylinder->half_h = cylinder->height / 2;
	g_scene.cy += 1;
	free (linekeep);
	*line = NULL;
}
