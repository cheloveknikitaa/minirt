/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:27:41 by caugusta          #+#    #+#             */
/*   Updated: 2021/08/10 17:27:12 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	cointersect(t_vec3 ro, t_vec3 rd, t_cone *cone)
{
	t_vec3	oc;
	t_vec3	abc;
	double	d1;
	double	d2;
	t_vec2	t;

	oc = vec3_sub(ro, cone->c);
	d1 = vec3_dot(rd, cone->nv);
	d2 = vec3_dot(oc, cone->nv);
	abc.x = vec3_dot(rd, rd) - pow(d1, 2.0) * (1 + pow(cone->m, 2.0));
	abc.y = 2 * (vec3_dot(rd, oc) - d1 * d2 * (1 + pow(cone->m, 2.0)));
	abc.z = vec3_dot(oc, oc) - pow(d2, 2.0) * (1 + pow(cone->m, 2.0));
	t = solve_quadratic(abc.x, abc.y, abc.z);
	if (t.x < 0)
	{
		t.x = t.y;
		if (t.x < 0)
			return (-1.0);
	}
	return (cone_solve(ro, rd, t, cone));
}

double	cone_solve(t_vec3 ro, t_vec3 rd, t_vec2 t, t_cone *cone)
{
	t_vec3	cp;

	cone->mint = t.x - 0.00001;
	cone->p = vec3_add(ro, vec3_mulS(rd, cone->mint));
	cp = vec3_sub(cone->p, cone->c);
	if (vec3_dot(cp, cone->nv) < 0.0 || vec3_dot(cp, cone->nv) > cone->h)
	{
		cone->mint = t.y - 0.00001;
		cone->p = vec3_add(ro, vec3_mulS(rd, cone->mint));
		cp = vec3_sub(cone->p, cone->c);
		if (vec3_dot(cp, cone->nv) < 0.0 || vec3_dot(cp, cone->nv) > cone->h)
			return (-1.0);
		else
			return (cone_normal(cp, rd, cone));
	}
	else
		return (cone_normal(cp, rd, cone));
	return (-1.0);
}

double	cone_normal(t_vec3 cp, t_vec3 rd, t_cone *cone)
{
	cone->n = vec3_mulS(cp, vec3_dot(cone->nv, cp));
	cone->n = vec3_mulS(cone->n, 1 / vec3_dot(cp, cp));
	cone->n = vec3_norm(vec3_sub(cone->n, cone->nv));
	if (vec3_dot(rd, cone->n) > 0)
		cone->n = vec3_mulS(cone->n, -1);
	return (cone->mint);
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
	cone->m = (cone->ra * 2.0) / (cone->h * 2.0);
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
