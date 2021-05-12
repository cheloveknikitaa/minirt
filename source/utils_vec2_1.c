/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec2_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 21:10:19 by caugusta          #+#    #+#             */
/*   Updated: 2021/05/12 21:28:21 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	vec2_lenght(t_vec2 a)
{
	float	len;

	len = sqrt(a.x * a.x + a.y * a.y);
	return (len);
}

t_vec2	vec2_norm(t_vec2 a)
{
	a = vec2_mulS(a, 1 / vec2_lenght(a));
	return (a);
}

t_vec2	vec2_reflect(t_vec2 rd, t_vec2 n)
{
	t_vec2	reflect;

	reflect = vec2_sub(rd, vec2_mulS(n, 2 * vec2_dot(n, rd)));
	return (reflect);
}
