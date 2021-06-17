/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 00:25:00 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/17 15:56:20 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_UTILS_H
# define SPHERE_UTILS_H
# include "vec2_utils.h"
# include "vec3_utils.h"

typedef struct s_sphere
{
	t_vec3			center;
	double			ra;
	t_vec3			color;
}				t_sphere;

t_vec2	sphIntersect(t_vec3 ro, t_vec3 rd, double ra, t_vec3 center);

#endif