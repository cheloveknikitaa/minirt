/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 00:39:49 by caugusta          #+#    #+#             */
/*   Updated: 2021/07/04 13:55:16 by caugusta         ###   ########.fr       */
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
	double		half_h;
	t_vec3		color;
	t_vec3		oc;
	t_vec3		ca;
}				t_cylinder;

t_vec2	cyintersect(t_vec3 ro, t_vec3 rd, t_cylinder *cy);
t_vec2	new_normal_body(t_vec2 t, t_cylinder *cy, t_vec3 rd, double y);
t_vec2	new_normal_caps(t_vec2 t, t_cylinder *cy, t_vec3 rd, double a[5]);
void	init_cy(char **line, t_cylinder *cylinder);

#endif