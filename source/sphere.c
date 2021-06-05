/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:54:45 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/05 17:21:49 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec2	sphIntersect(t_vec3 ro, t_vec3 rd, float ra, t_vec3 center)
{
	float	b;
	float	c;
	float	h;
	t_vec3	oc;

	oc = vec3_sub(ro, center);
	b = vec3_dot(oc, rd);
	c = vec3_dot(oc, oc) - ra * ra;
	h = b * b - c;
	if (h < 0.0)
		return (new_vec2(-1.0, -1.0));
	h = sqrt(h);
	return (new_vec2(-b - h, -b + h));
}
