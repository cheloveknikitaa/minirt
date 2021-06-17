/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:55:03 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/17 17:59:08 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	plaIntersect(t_vec3 ro, t_vec3 rd, t_plane *pl)
{
	double	d;
	double	dist;
	t_vec3	a;

	d = vec3_dot(pl->n, rd);
	// if (d > 0)
	// 	pl->n = vec3_mulS(pl->n, -1);
	if (d > 1e-6)
	{
		a = vec3_sub(pl->ro, ro);
		dist = vec3_dot(a, pl->n) / d;
		return (dist);
	}
	return (-1.0);
}
