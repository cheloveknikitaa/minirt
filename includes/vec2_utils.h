/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 10:38:37 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/05 10:38:40 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC2_UTILS_H
# define VEC2_UTILS_H

typedef struct s_vec2
{
	float		x;
	float		y;
}				t_vec2;

t_vec2	vec2_add(t_vec2 a, t_vec2 b);
t_vec2	vec2_sub(t_vec2 a, t_vec2 b);
t_vec2	vec2_mul(t_vec2 a, t_vec2 b);
t_vec2	vec2_mulS(t_vec2 a, float value);
double	vec2_dot(t_vec2 a, t_vec2 b);
float	vec2_lenght(t_vec2 a);
t_vec2	vec2_norm(t_vec2 a);
t_vec2	vec2_reflect(t_vec2 rd, t_vec2 n);
t_vec2	new_vec2(float x, float y);

#endif
