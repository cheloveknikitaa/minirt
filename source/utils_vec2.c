/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:03:23 by caugusta          #+#    #+#             */
/*   Updated: 2021/05/12 21:28:16 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec2	vec2_add(t_vec2 a, t_vec2 b)
{
	t_vec2	add;

	add.x = a.x + b.x;
	add.y = a.y + b.y;
	return (add);
}

t_vec2	vec2_sub(t_vec2 a, t_vec2 b)
{
	t_vec2	sub;

	sub.x = a.x - b.x;
	sub.y = a.y - b.y;
	return (sub);
}

t_vec2	vec2_mul(t_vec2 a, t_vec2 b)
{
	t_vec2	mul;

	mul.x = a.x * b.x;
	mul.y = a.y * b.y;
	return (mul);
}

t_vec2	vec2_mulS(t_vec2 a, float value)
{
	t_vec2	mulS;

	mulS.x = a.x * value;
	mulS.y = a.y * value;
	return (mulS);
}

double	vec2_dot(t_vec2 a, t_vec2 b)
{
	double	dot;

	dot = a.x * b.x + a.y * b.y;
	return (dot);
}
