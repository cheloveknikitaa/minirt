/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:55:43 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/29 21:03:42 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// double	cyintersect(t_vec3 ro, t_vec3 rd, t_cylinder *cy)
// {
// 	t_vec3	ba;
// 	t_vec3	oc;
// 	double	t;
// 	double	y;
// 	double	h;

// 	ba = vec3_sub(cy->pb, cy->pa);
// 	oc = vec3_sub(ro, cy->pa);
// 	cykcalc(ba, oc, &cy, rd);
// 	h = cy->k1 * cy->k1 - cy->k2 * cy->k0;
// 	if (h < 0.0)
// 		return (-1);
// 	h = sqrtf(h);
// 	t = (-cy->k1 - h) / cy->k2;
// 	y = vec3_dot(ba, oc) + t * vec3_dot(ba, rd);
// 	if (y > 0.0 && y < vec3_dot(ba, ba))
// 		return (t);
// 	y = idiotizm(y, ba);
// 	t = (y - vec3_dot(ba, oc)) / vec3_dot(ba, rd);
// 	if (fabs(cy->k1 + cy->k2 * t) < h)
// 		return (t);
// 	return (-1);
// }

// void	cykcalc(t_vec3 ba, t_vec3 oc, t_cylinder *cy, t_vec3 rd)
// {
// 	cy->k2 = vec3_dot(ba, ba) - vec3_dot(ba, rd) * vec3_dot(ba, rd);
// 	cy->k1 = vec3_dot(ba, ba) * vec3_dot(oc, rd) - vec3_dot(ba, oc) * \
// 		vec3_dot(ba, rd);
// 	cy->k0 = vec3_dot(ba, ba) * vec3_dot(oc, oc) - vec3_dot(ba, oc) * \
// 		vec3_dot(ba, oc) - cy->ra * cy->ra * vec3_dot(ba, ba);
// }

// double	idiotizm(double y, t_vec3 ba)
// {
// 	if (y < 0.0)
// 		y = 0.0;
// 	else
// 		y = vec3_dot(ba, ba);
// 	return (y);
// }
