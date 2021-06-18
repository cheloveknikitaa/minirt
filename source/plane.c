/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:55:03 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/18 19:11:15 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	plaIntersect(t_vec3 ro, t_vec3 rd, t_plane *pl)
{
	double	r;
	double	t;
	
	
	// double	d;
	// double	dmod;
	// double	dist;
	// t_vec3	a;

	// d = vec3_dot(pl->n, rd);
	// if (d < 0)
	// 	dmod = -d;
	// else
	// 	dmod = d;
	// if (dmod < DBL_EPSILON)
	// 	return (-1.0);
	// a = vec3_sub(pl->ro, ro);
	// dist = vec3_dot(a, pl->n) / d;
	// if (dist > DBL_EPSILON)
	// {
	// 	if (d > 0)
	// 		pl->n = vec3_mulS(pl->n, -1);
	// 	return (dist);
	// }
	// return (-1.0);
}

double	plaIntersect1(t_vec3 ro, t_vec3 rd, t_plane pl)
{
	double	d;

	d = -(pl.n.x * pl.ro.x) - (pl.n.y * \
		pl.ro.y) - (pl.n.z * pl.ro.z);
	return (-(vec3_dot(ro, pl.n) + d) / vec3_dot(rd, pl.n));
}
