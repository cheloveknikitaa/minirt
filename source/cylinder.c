/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:55:43 by caugusta          #+#    #+#             */
/*   Updated: 2021/08/09 17:31:44 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
// double	cyintersect(t_vec3 ro, t_vec3 rd, t_cylinder *cy)
// {
// 	double	a, b, c, h, m;
// 	t_vec2	t;
// 	t_vec3	x;
// 	t_vec3	p_a;

// 	x = vec3_sub(ro, cy->pa);
// 	a = vec3_dot(rd, rd) - pow(vec3_dot(rd, cy->nv), 2.0);
// 	b = (vec3_dot(rd, x) - vec3_dot(rd, cy->nv) * vec3_dot(x, cy->nv)) * 2.0;
// 	c = vec3_dot(x, x) - pow(vec3_dot(x, cy->nv), 2.0) - pow(cy->ra, 2.0);
// 	h = b * b - 4 * a * c;
// 	if (h < 0.0)
// 		return (-1.0);
// 	h = sqrt(h);
// 	t.x = (-b + h) / (2 * a);
// 	t.y = (-b - h) / (2 * a);
// 	m = vec3_dot(rd, cy->nv) * t.x + vec3_dot(x, cy->nv);
// 	if (fabs(m) < cy->height)
// 	{
// 		cy->mint = t.x;
// 		cy->p = vec3_add(ro, vec3_mulS(rd, cy->mint));
// 		p_a = vec3_sub(cy->p, (vec3_add(cy->pa, vec3_mulS(cy->nv, m))));
// 		// if (vec3_dot(p_a, cy->nv) == 0.0 || vec3_lenght(p_a) == cy->ra)
// 		// {
// 			cy->n = vec3_norm(vec3_sub(vec3_sub(cy->p, cy->pa), \
// 			vec3_mulS(cy->nv, m)));
// 			return (t.x);
// 		// }
// 	}
// 	m = vec3_dot(rd, cy->nv) * t.y + vec3_dot(x, cy->nv);
// 	if (fabs(m) < cy->height)
// 	{
// 		cy->mint = t.y;
// 		cy->p = vec3_add(ro, vec3_mulS(rd, cy->mint));
// 		p_a = vec3_sub(cy->p, (vec3_add(cy->pa, vec3_mulS(cy->nv, m))));
// 		// if (vec3_dot(p_a, cy->nv) == 0.0 || vec3_lenght(p_a) == cy->ra)
// 		// {
// 			cy->n = vec3_norm(vec3_sub(vec3_sub(cy->p, cy->pa), \
// 			vec3_mulS(cy->nv, m)));
// 			return (t.y);
// 		// }
// 	}
// 	return (-1.0);
// }

double	cyintersect(t_vec3 ro, t_vec3 rd, t_cylinder *cy)
{
	t_vec2	t;
	double	y;
	double	y1;
	double	h;
	double	ch;
	double	a;
	double	b;
	double	c;
	t_vec3	ca;
	t_vec3	x;

	x = vec3_sub(ro, cy->pa);
	ch = vec3_lenght(cy->ba);
	ca = vec3_mulS(cy->ba, 1 / ch);
	ch *= 0.5;
	cy->oc = vec3_sub(ro, cy->c);
	a = vec3_dot(rd, rd) - pow(vec3_dot(rd, cy->nv), 2.0);
	b = (vec3_dot(rd, x) - vec3_dot(rd, cy->nv) * vec3_dot(x, cy->nv)) * 2;
	c = vec3_dot(x, x) - pow(vec3_dot(x, cy->nv), 2.0) - pow(cy->ra, 2.0);
	h = b * b - 4 * a * c;
	if (h < 0.0)
		return (-1.0);
	h = sqrt(h);
	t.x = (-b + h) / (2 * a);
	t.y = (-b - h) / (2 * a);
	y = vec3_dot(ca, cy->oc) + min(t.x, t.y) * vec3_dot(ca, rd);
	y1 = vec3_dot(ca, cy->oc) + max(t.x, t.y) * vec3_dot(ca, rd);
	if (ro.x != g_scene.cam.ro.x && ro.y != g_scene.cam.ro.y && \
		ro.z != g_scene.cam.ro.z)
	{
		if (fabs(y1) < ch)
		{
			cy->mint = max(t.x, t.y);
			return (cy->mint);
		}
		if (fabs(y) < ch)
		{
			cy->mint = min(t.x, t.y);
			return (cy->mint);
		}
	}
	if (fabs(min(y, y1)) < ch)
	{
		cy->mint = min(t.x, t.y);
		cy->p = vec3_add(ro, vec3_mulS(rd, cy->mint));
		// cy->n = vec3_norm(vec3_sub(vec3_add(cy->oc, vec3_mulS(rd, cy->mint)), vec3_mulS(ca, y)));
		
		cy->n = vec3_norm(vec3_sub(vec3_sub(cy->p, cy->pa), vec3_mulS(cy->nv, vec3_dot(rd, cy->nv) * cy->mint + vec3_dot(x, cy->nv))));
		return (cy->mint);
	}
	if (fabs(max(y, y1)) < ch)
	{
		cy->mint = max(t.x, t.y);
		cy->p = vec3_add(ro, vec3_mulS(rd, cy->mint));
		// cy->n = vec3_norm(vec3_sub(vec3_add(cy->oc, vec3_mulS(rd, cy->mint)), vec3_mulS(ca, y)));
		cy->n = vec3_norm(vec3_sub(vec3_sub(cy->p, cy->pa), vec3_mulS(cy->nv, vec3_dot(rd, cy->nv) * cy->mint + vec3_dot(x, cy->nv))));
		return (cy->mint);
	}
	return (-1.0);
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
	g_scene.cy += 1;
	free (linekeep);
	*line = NULL;
}

// double	new_normal_body(double t, t_cylinder *cy, t_vec3 ro, t_vec3 rd)
// {
	// double	where_cam;
	// double	where_light;

	// where_cam = pow((g_scene.cam.ro.x - cy->c.x), 2.0) + \
	// 	pow((g_scene.cam.ro.y - cy->c.y), 2.0) + \
	// 	pow((g_scene.cam.ro.z - cy->c.z), 2.0);
	// where_light = pow((g_scene.light.ro.x - cy->c.x), 2.0) + \
	// 	pow((g_scene.light.ro.y - cy->c.y), 2.0) + \
	// 	pow((g_scene.light.ro.z - cy->c.z), 2.0);
	// if (vec3_dot(ro, ro) != vec3_dot(g_scene.cam.ro, g_scene.cam.ro) && \
	// 	where_light < pow(cy->ra, 2.0))
	// 	return (t);
	// if (where_cam < pow(cy->ra, 2.0))
	// 	cy->mint = t;
	// else
	// 	cy->mint = t;
	// cy->n = vec3_norm(vec3_sub(vec3_add(cy->oc, vec3_mulS(rd, t)), vec3_mulS(ca, y)));
	// cy->p = vec3_add(ro, vec3_mulS(rd, cy->mint));
// 	return (cy->mint);
// }

double	new_normal_caps(double t, t_cylinder *cy, double y)
{
	t_vec3	xbody;
	double	interbody;
	double	intercap;

	if (y < 0)
		y = -1;
	else if (y > 0)
		y = 1;
	else if (y == 0)
		y = 0;
	xbody = vec3_mulS(cy->nv, vec3_dot(vec3_sub(cy->p, cy->c), cy->nv));
	xbody = vec3_sub(vec3_sub(cy->p, cy->c), xbody);
	interbody = vec3_lenght(xbody);
	intercap = pow(vec3_dot(vec3_sub(cy->p, cy->c), cy->nv), 2.0);
	if (interbody > cy->ra && intercap > pow(cy->height / 2.0, 2.0))
		return (-1.0);
	cy->n = vec3_mulS(vec3_mulS(cy->ba, y), (1 / vec3_dot(cy->ba, cy->ba)));
	cy->mint = t;
	return (t);
}

t_vec3	cycolor(double *mint, t_vec3 *p, t_vec3 *n, t_cylinder	cy)
{
	*mint = cy.mint;
	*p = cy.p;
	*n = cy.n;
	return (cy.color);
}

// double	


// It's using the ray equation and the clyinder equation. SImilar to this
// ray : P(t) = P + V * t
// cyl : (((P(t) - O) x D)^2 = r^2
// O is point on cylinder core, D is direction of cylinder (normalised), r is radius.
// then you combine the two equations and you get a second order equation you solve for (t), composed of cross products and dot products.
// with end points B and A...
// (((P(t) - A) x (B - A))^2 = r^2 * ((B - A) . (B - A))

//---------------------------------------------------------------------------//
// Ray : P(t) = O + V * t
// Cylinder [O, D, r].
// point Q on cylinder 
// if ((Q - O) x D)^2 = r^2//
// Cylinder [A, B, r].
// Point P on infinite cylinder
// if ((P - A) x (B - A))^2 = r^2 * (B - A)^2
// expand : ((O - A) x (B - A) + t * (V x (B - A)))^2 = r^2 * (B - A)^2
// equation in the form (X + t * Y)^2 = d
// where :
//  X = (O - A) x (B - A)
//  Y = V x (B - A)
//  d = r^2 * (B - A)^2
// expand the equation :
// t^2 * (Y . Y) + t * (2 * (X . Y)) + (X . X) - d = 0
// => second order equation in the form : a*t^2 + b*t + c = 0 where
// a = (Y . Y)// b = 2 * (X . Y)// c = (X . X) - d
// Vector AB = (B - A);Vector AO = (O - A);Vector AOxAB = (AO ^ AB);
// cross productVector VxAB  = (V ^ AB);
// cross productfloat  ab2   = (AB * AB);
// dot productfloat a      = (VxAB * VxAB);
// dot productfloat b      = 2 * (VxAB * AOxAB);
// dot productfloat c      = (AOxAB * AOxAB) - (r*r * ab2);
// solve second order equation : a*t^2 + b*t + c = 0
// --------------------------------------------------------------------------//