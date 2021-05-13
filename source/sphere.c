/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:54:45 by caugusta          #+#    #+#             */
/*   Updated: 2021/05/13 15:29:24 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec2	*sphIntersect(t_vec3 *ro, t_vec3 *rd, float ra)
{
	float	b;
	float	c;
	float	h;

	b = vec3_dot(ro, rd);
	c = vec3_dot(ro, ro) - ra * ra;
	h = b * b - c;
	if (h < 0.0)
		return (new_vec2(-1.0, -1.0));
	h = sqrt(h);
	return (new_vec2(-b - h, -b + h));
}
