/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:55:43 by caugusta          #+#    #+#             */
/*   Updated: 2021/08/09 22:28:43 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	cyintersect(t_vec3 ro, t_vec3 rd, t_cylinder *cy)
{
	t_vec2	t;
	double	a;
	double	b;
	double	c;

	cy->x = vec3_sub(ro, cy->pa);
	cy->oc = vec3_sub(ro, cy->c);
	a = vec3_dot(rd, rd) - pow(vec3_dot(rd, cy->nv), 2.0);
	b = (vec3_dot(rd, cy->x) - vec3_dot(rd, cy->nv) * \
		vec3_dot(cy->x, cy->nv)) * 2;
	c = vec3_dot(cy->x, cy->x) - pow(vec3_dot(cy->x, cy->nv), 2.0) - \
		pow(cy->ra, 2.0);
	t = solve_quadratic(a, b, c);
	if (t.x < 0)
	{
		t.x = t.y;
		if (t.x < 0)
			return (-1.0);
	}
	return (new_normal_body(t, cy, ro, rd));
}

void	init_cy(char **line, t_cylinder *cylinder)
{
	char	*linekeep;

	linekeep = *line;
	*line = *line + 2;
	cylinder->pa = pars_vec3(line);
	cylinder->nv = pars_vec3_norm(line);
	cylinder->ra = ft_atof(line) / 2;
	if (cylinder->ra < 0)
		exit_err(3);
	cylinder->height = ft_atof(line);
	if (cylinder->height < 0)
		exit_err(3);
	cylinder->color = rgb_to_xyz(pars_vec3_color(line));
	cylinder->pb = vec3_add(vec3_mulS(cylinder->nv, cylinder->height), \
		cylinder->pa);
	cylinder->c = vec3_add(vec3_mulS(cylinder->nv, (cylinder->height / 2)), \
		cylinder->pa);
	cylinder->ba = vec3_sub(cylinder->pb, cylinder->pa);
	cylinder->ca = vec3_mulS(cylinder->ba, 1 / vec3_lenght(cylinder->ba));
	cylinder->ch = vec3_lenght(cylinder->ba) * 0.5;
	g_scene.cy += 1;
	free (linekeep);
	*line = NULL;
}

double	new_normal_body(t_vec2 t, t_cylinder *cy, t_vec3 ro, t_vec3 rd)
{
	t_vec2	y;
	t_vec3	m;

	y.x = vec3_dot(cy->ca, cy->oc) + t.x * vec3_dot(cy->ca, rd);
	y.y = vec3_dot(cy->ca, cy->oc) + t.y * vec3_dot(cy->ca, rd);
	if (fabs(y.x) < cy->ch)
	{
		cy->mint = t.x - 0.001;
		cy->p = vec3_add(ro, vec3_mulS(rd, cy->mint));
		m = vec3_sub(cy->p, cy->pa);
		// cy->n = vec3_norm(vec3_sub(m, vec3_mulS(cy->nv, vec3_dot(cy->nv, m))));
		cy->n = vec3_norm(vec3_sub(vec3_add(cy->oc, vec3_mulS(rd, cy->mint)), vec3_mulS(cy->ca, y.x)));
		// cy->n = vec3_norm(vec3_sub(vec3_sub(cy->p, cy->pa), \
		vec3_mulS(cy->nv, vec3_dot(rd, cy->nv) * cy->mint + vec3_dot(cy->x, cy->nv))));
	}
	else if (fabs(y.y) < cy->ch)
	{
		cy->mint = t.y - 0.001;
		cy->p = vec3_add(ro, vec3_mulS(rd, cy->mint));
		m = vec3_sub(cy->p, cy->pa);
		// cy->n = vec3_norm(vec3_sub(m, vec3_mulS(cy->nv, vec3_dot(cy->nv, m))));
		cy->n = vec3_norm(vec3_sub(vec3_add(cy->oc, vec3_mulS(rd, cy->mint)), vec3_mulS(cy->ca, y.y)));
		// cy->n = vec3_norm(vec3_sub(vec3_sub(cy->p, cy->pa), \
		vec3_mulS(cy->nv, vec3_dot(rd, cy->nv) * cy->mint + vec3_dot(cy->x, cy->nv))));
	}
	else
		return (-1.0);
	if (vec3_dot(rd, cy->n) > 0)
		cy->n = vec3_mulS(cy->n, -1);
	return (cy->mint);
}

t_vec3	cycolor(double *mint, t_vec3 *p, t_vec3 *n, t_cylinder	cy)
{
	*mint = cy.mint;
	*p = cy.p;
	*n = cy.n;
	return (cy.color);
}
