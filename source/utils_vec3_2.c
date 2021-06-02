/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec3_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:43:22 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/02 14:50:17 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	*vec3_cross(t_vec3 *a, t_vec3 *b)
{
	t_vec3	*result;

	result->x = (a->y * b->z) - (a->z * b->y);
	result->y = (a->z * b->x) - (a->x * b->z);
	result->z = (a->x * b->y) - (a->y * b->x);
	return (result);
}
