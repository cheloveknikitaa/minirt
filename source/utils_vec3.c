/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 21:26:55 by caugusta          #+#    #+#             */
/*   Updated: 2021/05/19 05:31:36 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	*vec3_add(t_vec3 *a, t_vec3 *b)
{
	t_vec3	*add;

	add = malloc(sizeof(t_vec3));
	add->x = a->x + b->x;
	add->y = a->y + b->y;
	add->z = a->z + b->z;
	return (add);
}

t_vec3	*vec3_sub(t_vec3 *a, t_vec3 *b)
{
	t_vec3	*sub;

	sub = malloc(sizeof(t_vec3));
	sub->x = a->x - b->x;
	sub->y = a->y - b->y;
	sub->z = a->z - b->z;
	return (sub);
}

t_vec3	*vec3_mul(t_vec3 *a, t_vec3 *b)
{
	t_vec3	*mul;

	mul = malloc(sizeof(t_vec3));
	mul->x = a->x * b->x;
	mul->y = a->y * b->y;
	mul->z = a->z * b->z;
	return (mul);
}

t_vec3	*vec3_mulS(t_vec3 *a, float value)
{
	t_vec3	*mulS;

	mulS = malloc(sizeof(t_vec3));
	mulS->x = a->x * value;
	mulS->y = a->y * value;
	mulS->z = a->z * value;
	return (mulS);
}

float	vec3_dot(t_vec3 *a, t_vec3 *b)
{
	float	dot;

	dot = a->x * b->x + a->y * b->y + a->z * b->z;
	return (dot);
}
