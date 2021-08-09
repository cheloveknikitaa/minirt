/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita <nikita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 00:25:00 by caugusta          #+#    #+#             */
/*   Updated: 2021/07/31 14:46:58 by nikita           ###   ########.fr       */
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
double	sp_new_normal(t_sphere *sp, t_vec2 t, t_vec3 ro, t_vec3 rd);
t_vec3	spcolor(double *mint, t_vec3 *p, t_vec3 *n, t_sphere sp);

#endif