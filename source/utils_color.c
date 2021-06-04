/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:12:10 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/04 11:16:07 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	write_color(t_data *scene, t_vec3 *ray)
{
	int	r;
	int	g;
	int	b;

	r = 255.999 * ray->x;
	g = 255.999 * ray->y;
	b = 255.999 * ray->z;
	scene->color->x = r * 256 * 256;
	scene->color->y = g * 256;
	scene->color->z = b;
	scene->int_color = scene->color->x + scene->color->y + scene->color->z;
}
