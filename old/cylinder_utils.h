/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 00:39:49 by caugusta          #+#    #+#             */
/*   Updated: 2021/08/09 22:07:48 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_UTILS_H
# define CYLINDER_UTILS_H
# include "miniRT.h"

typedef struct s_cylinder
{
	t_vec3		pa;
	t_vec3		pb;
	t_vec3		n;
	t_vec3		nv;
	t_vec3		c;
	t_vec3		p;
	double		ra;
	double		height;
	t_vec3		color;
	t_vec3		ba;
	t_vec3		oc;
	double		ch;
	t_vec3		ca;
	t_vec3		x;
	double		mint;
}				t_cylinder;

double	cyintersect(t_vec3 ro, t_vec3 rd, t_cylinder *cy);
void	init_cy(char **line, t_cylinder *cylinder);
double	new_normal_body(t_vec2 t, t_cylinder *cy, t_vec3 ro, t_vec3 rd);
t_vec3	cycolor(double *mint, t_vec3 *p, t_vec3 *n, t_cylinder	cy);

#endif