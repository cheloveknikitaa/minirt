/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:55:43 by caugusta          #+#    #+#             */
/*   Updated: 2021/07/03 22:19:09 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	cyintersect(t_vec3 ro, t_vec3 rd, t_cylinder *cy)
{
	double	t;
	double	y;
	double	ynew;
	double	h;

	cy->ba = vec3_sub(cy->pb, cy->pa);
	cy->oc = vec3_sub(ro, cy->pa);
	cykcalc(cy->ba, cy->oc, cy, rd);
	h = cy->k1 * cy->k1 - cy->k2 * cy->k0;
	if (h < 0.0)
		return (-1.0);
	h = sqrtf(h);
	t = (-cy->k1 - h) / cy->k2;
	y = vec3_dot(cy->ba, cy->oc) + t * vec3_dot(cy->ba, rd);
	if (y > 0.0 && y < vec3_dot(cy->ba, cy->ba))
		return (new_normal_body(t, cy, rd, y));
	ynew = idiotizm(y, cy->ba);
	t = (ynew - vec3_dot(cy->ba, cy->oc)) / vec3_dot(cy->ba, rd);
	if (fabs(cy->k1 + cy->k2 * t) < h)
		return (new_normal_caps(t, cy, y));
	return (-1.0);
}

void	cykcalc(t_vec3 ba, t_vec3 oc, t_cylinder *cy, t_vec3 rd)
{
	cy->k2 = vec3_dot(ba, ba) - vec3_dot(ba, rd) * vec3_dot(ba, rd);
	cy->k1 = vec3_dot(ba, ba) * vec3_dot(oc, rd) - vec3_dot(ba, oc) * \
		vec3_dot(ba, rd);
	cy->k0 = vec3_dot(ba, ba) * vec3_dot(oc, oc) - vec3_dot(ba, oc) * \
		vec3_dot(ba, oc) - cy->ra * cy->ra * vec3_dot(ba, ba);
}

double	idiotizm(double y, t_vec3 ba)
{
	if (y < 0.0)
		y = 0.0;
	else
		y = vec3_dot(ba, ba);
	return (y);
}

void	init_cy(char **line, t_cylinder *cylinder)
{
	char	*linekeep;

	linekeep = *line;
	*line = *line + 2;
	cylinder->pa = pars_vec3(line);
	cylinder->n = pars_vec3_norm(line);
	cylinder->ra = ft_atof(line) / 2;
	cylinder->height = ft_atof(line);
	cylinder->color = rgb_to_xyz(pars_vec3_color(line));
	cylinder->pb = vec3_add(vec3_mulS(cylinder->n, cylinder->height), \
		cylinder->pa);
	g_scene.cy += 1;
	free (linekeep);
	*line = NULL;
}

double	new_normal_body(double t, t_cylinder *cy, t_vec3 rd, double y)
{
	cy->n = vec3_mulS(vec3_sub(vec3_add(cy->oc, vec3_mulS(rd, t)), vec3_mulS(\
				vec3_mulS(cy->ba, y), 1 / vec3_dot(cy->ba, cy->ba))), \
					1 / cy->ra);
	return (t);
}

double	new_normal_caps(double t, t_cylinder *cy, double y)
{
	if (y < 0)
		y = -1;
	else if (y > 0)
		y = 1;
	else if (y == 0)
		y = 0;
	cy->n = vec3_mulS(vec3_mulS(cy->ba, y), (1 / vec3_dot(cy->ba, cy->ba)));
	return (t);
}


double	cyintersect_shadow(t_vec3 ro, t_vec3 rd, t_cylinder *cy)
{
	double	t;
	double	y;
	double	ynew;
	double	h;

	cy->ba = vec3_sub(cy->pb, cy->pa);
	cy->oc = vec3_sub(ro, cy->pa);
	cykcalc(cy->ba, cy->oc, cy, rd);
	h = cy->k1 * cy->k1 - cy->k2 * cy->k0;
	if (h < 0.0)
		return (-1.0);
	h = sqrtf(h);
	t = (-cy->k1 - h) / cy->k2;
	y = vec3_dot(cy->ba, cy->oc) + t * vec3_dot(cy->ba, rd);
	if (y > 0.0 && y < vec3_dot(cy->ba, cy->ba))
		return (t);
	ynew = idiotizm(y, cy->ba);
	t = (ynew - vec3_dot(cy->ba, cy->oc)) / vec3_dot(cy->ba, rd);
	if (fabs(cy->k1 + cy->k2 * t) < h)
		return (t);
	return (-1.0);
}