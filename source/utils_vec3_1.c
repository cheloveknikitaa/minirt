/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec3_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 22:49:36 by caugusta          #+#    #+#             */
/*   Updated: 2021/05/12 22:51:44 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	vec3_lenght(t_vec3 a)
{
	float	len;

	len = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
	return (len);
}

t_vec3	vec3_norm(t_vec3 a)
{
	a = vec3_mulS(a, 1 / vec3_lenght(a));
	return (a);
}

t_vec3	vec3_reflect(t_vec3 rd, t_vec3 n)
{
	t_vec3	reflect;

	reflect = vec3_sub(rd, vec3_mulS(n, 2 * vec3_dot(n, rd)));
	return (reflect);
}
