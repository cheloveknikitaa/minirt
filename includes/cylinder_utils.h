/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 00:39:49 by caugusta          #+#    #+#             */
/*   Updated: 2021/07/04 09:04:18 by caugusta         ###   ########.fr       */
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
	double		k0;
	double		k1;
	double		k2;
	t_vec3		ba;
	t_vec3		oc;
}				t_cylinder;

double	cyintersect(t_vec3 ro, t_vec3 rd, t_cylinder *cy);
void	cykcalc(t_vec3 ba, t_vec3 oc, t_cylinder *cy, t_vec3 rd);
void	init_cy(char **line, t_cylinder *cylinder);
double	idiotizm(double y, t_vec3 ba);
void	init_cy(char **line, t_cylinder *cylinder);
double	new_normal_body(double t, t_cylinder *cy, t_vec3 rd, double y);
double	new_normal_caps(double t, t_cylinder *cy, double y);
double	cyintersect_shadow(t_vec3 ro, t_vec3 rd, t_cylinder cy);

#endif