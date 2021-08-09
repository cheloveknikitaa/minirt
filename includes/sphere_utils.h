/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 00:25:00 by caugusta          #+#    #+#             */
/*   Updated: 2021/08/09 20:14:15 by caugusta         ###   ########.fr       */
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
	double			mint;
	t_vec3			color;
	t_vec3			n;
	t_vec3			p;
}				t_sphere;

double	sphIntersect(t_vec3 ro, t_vec3 rd, t_sphere *sp);
void	init_sphere(char **line, t_sphere *sphere);
t_vec3	spcolor(double *mint, t_vec3 *p, t_vec3 *n, t_sphere sp);

#endif