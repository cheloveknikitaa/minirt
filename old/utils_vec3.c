/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 10:35:19 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/08 18:10:45 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	vec3_add(t_vec3 a, t_vec3 b)
{
	t_vec3	add;

	add.x = a.x + b.x;
	add.y = a.y + b.y;
	add.z = a.z + b.z;
	return (add);
}

t_vec3	vec3_sub(t_vec3 a, t_vec3 b)
{
	t_vec3	sub;

	sub.x = a.x - b.x;
	sub.y = a.y - b.y;
	sub.z = a.z - b.z;
	return (sub);
}

t_vec3	vec3_mul(t_vec3 a, t_vec3 b)
{
	t_vec3	mul;

	mul.x = a.x * b.x;
	mul.y = a.y * b.y;
	mul.z = a.z * b.z;
	return (mul);
}

t_vec3	vec3_mulS(t_vec3 a, double value)
{
	t_vec3	mulS;

	mulS.x = a.x * value;
	mulS.y = a.y * value;
	mulS.z = a.z * value;
	return (mulS);
}

double	vec3_dot(t_vec3 a, t_vec3 b)
{
	double	dot;

	dot = a.x * b.x + a.y * b.y + a.z * b.z;
	return (dot);
}
