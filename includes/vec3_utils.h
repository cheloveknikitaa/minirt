/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 10:38:14 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/08 18:11:50 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_UTILS_H
# define VEC3_UTILS_H

typedef struct s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

t_vec3	vec3_add(t_vec3 a, t_vec3 b);
t_vec3	vec3_sub(t_vec3 a, t_vec3 b);
t_vec3	vec3_mul(t_vec3 a, t_vec3 b);
t_vec3	vec3_mulS(t_vec3 a, double value);
double	vec3_dot(t_vec3 a, t_vec3 b);
double	vec3_lenght(t_vec3 a);
t_vec3	vec3_norm(t_vec3 a);
t_vec3	vec3_reflect(t_vec3 rd, t_vec3 n);
t_vec3	new_vec3(double x, double y, double z);
t_vec3	vec3_div(t_vec3 a, double c);
t_vec3	vec3_cross(t_vec3 a, t_vec3 b);

#endif
