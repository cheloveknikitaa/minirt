/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 21:24:50 by caugusta          #+#    #+#             */
/*   Updated: 2021/05/12 22:51:03 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_UTILS_H
# define VEC3_UTILS_H
# include "miniRT.h"

t_vec3	vec3_add(t_vec3 a, t_vec3 b);
t_vec3	vec3_sub(t_vec3 a, t_vec3 b);
t_vec3	vec3_mul(t_vec3 a, t_vec3 b);
t_vec3	vec3_mulS(t_vec3 a, float value);
double	vec3_dot(t_vec3 a, t_vec3 b);
float	vec3_lenght(t_vec3 a);
t_vec3	vec3_norm(t_vec3 a);
t_vec3	vec3_reflect(t_vec3 rd, t_vec3 n);

#endif