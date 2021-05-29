/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 00:25:00 by caugusta          #+#    #+#             */
/*   Updated: 2021/05/29 06:13:21 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_UTILS_H
# define SPHERE_UTILS_H
# include "vec2_utils.h"
# include "vec3_utils.h"

typedef struct s_sphere
{
	t_vec3			*center;
	float			ra;
	t_vec3			*color;
	int				int_color;
	struct s_sphere	*next;
}				t_sphere;

t_vec2	*sphIntersect(t_vec3 *ro, t_vec3 *rd, float ra);

#endif