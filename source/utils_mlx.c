/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 01:21:31 by caugusta          #+#    #+#             */
/*   Updated: 2021/05/29 01:52:57 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

//t_vec3	*traceRay(t_vec3 *ro, t_vec3 *rd)
//{
//	t_vec3	*col;
//	int		i;
//
//	col = new_vec3(1.0, 1.0, 1.0);
//	i = 0;
//	while (i < 8)
//	{
//
//	}
//}

float	max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	min(float a, float b)
{
	if (a > b)
		return (b);
	else
		return (a);
}