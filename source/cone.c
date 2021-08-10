/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:27:41 by caugusta          #+#    #+#             */
/*   Updated: 2021/08/10 13:47:35 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	cointersect(t_vec3 ro, t_vec3 rd, t_cone *cone)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	d1;
	double	d2;
	t_vec2	t;
	t_vec3	cp;

	oc = vec3_sub(ro, cone->c);
	d1 = vec3_dot(rd, cone->nv);
	d2 = vec3_dot(oc, cone->nv);
	a = pow(d1, 2.0);
	a = vec3_dot(rd, rd) - cone->m * a - a;
	b = 2 * (vec3_dot(rd, oc) - cone->m * d1 * d2 - d1 * d2);
	c = vec3_dot(oc, oc) - cone->m * pow(d2, 2.0) - pow(d2, 2.0);
	t = solve_quadratic(a, b, c);
	if (t.x < 0)
	{
		t.x = t.y;
		if (t.x < 0)
			return (-1.0);
	}
	cone->mint = t.x - 0.001;
	cone->p = vec3_add(ro, vec3_mulS(rd, cone->mint));
	cp = vec3_sub(cone->p, cone->c);
	if (vec3_dot(cp, cone->nv) < 0.0 || vec3_dot(cp, cone->nv) > cone->h)
	{
		cone->mint = t.y - 0.001;
		cone->p = vec3_add(ro, vec3_mulS(rd, cone->mint));
		cp = vec3_sub(cone->p, cone->c);
		if (vec3_dot(cp, cone->nv) < 0.0 || vec3_dot(cp, cone->nv) > cone->h)
			return (-1.0);
		else
		{
			cone->n = vec3_norm(vec3_sub(vec3_mulS \
			(vec3_mulS(cp, vec3_dot(cone->nv, cp)), vec3_dot(cp, cp)), cone->nv));
			if (t.x == t.y)
				cone->n = vec3_mulS(cone->n, -1);
			return (cone->mint);
		}
	}
	else
	{
		cone->n = vec3_norm(vec3_sub(vec3_mulS \
		(vec3_mulS(cp, vec3_dot(cone->nv, cp)), vec3_dot(cp, cp)), cone->nv));
		if (t.x == t.y)
			cone->n = vec3_mulS(cone->n, -1);
		return (cone->mint);
	}
	return (-1.0);
}

void	init_cone(char **line, t_cone *cone)
{
	char	*linekeep;

	linekeep = *line;
	*line = *line + 2;
	cone->c = pars_vec3(line);
	cone->nv = pars_vec3_norm(line);
	cone->ra = ft_atof(line);
	if (cone->ra < 0)
		exit_err(3);
	cone->h = ft_atof(line);
	if (cone->h < 0)
		exit_err(3);
	cone->color = rgb_to_xyz(pars_vec3_color(line));
	cone->m = pow(cone->ra, 2.0) / pow(cone->h, 2.0);
	g_scene.co += 1;
	free (linekeep);
	*line = NULL;
}

t_vec3	cocolor(double *mint, t_vec3 *p, t_vec3 *n, t_cone co)
{
	*mint = co.mint;
	*p = co.p;
	*n = co.n;
	return (co.color);
}
