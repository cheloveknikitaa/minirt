/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:54:45 by caugusta          #+#    #+#             */
/*   Updated: 2021/08/09 20:14:50 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	sphIntersect(t_vec3 ro, t_vec3 rd, t_sphere	*sp)
{
	double	a;
	double	b;
	double	c;
	t_vec2	t;
	t_vec3	oc;

	oc = vec3_sub(ro, sp->center);
	a = vec3_dot(rd, rd);
	b = 2 * vec3_dot(oc, rd);
	c = vec3_dot(oc, oc) - sp->ra * sp->ra;
	t = solve_quadratic(a, b, c);
	if (t.x < 0)
	{
		t.x = t.y;
		if (t.x < 0)
			return (-1.0);
	}
	sp->mint = min(t.x, t.y);
	sp->p = vec3_add(ro, vec3_mulS(rd, sp->mint));
	sp->n = vec3_norm(vec3_sub(sp->p, sp->center));
	return (sp->mint);
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

t_vec3	spcolor(double *mint, t_vec3 *p, t_vec3 *n, t_sphere sp)
{
	*mint = sp.mint;
	*p = sp.p;
	*n = sp.n;
	return (sp.color);
}
