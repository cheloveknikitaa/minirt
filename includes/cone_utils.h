/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 20:52:29 by caugusta          #+#    #+#             */
/*   Updated: 2021/08/10 20:52:34 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONE_UTILS_H
# define CONE_UTILS_H
# include "miniRT.h"

typedef struct s_cone
{
	t_vec3		n;
	t_vec3		nv;
	t_vec3		c;
	t_vec3		p;
	double		ra;
	double		h;
	t_vec3		color;
	double		mint;
	double		m;
}				t_cone;

double	cointersect(t_vec3 ro, t_vec3 rd, t_cone *cone);
double	cone_solve(t_vec3 ro, t_vec3 rd, t_vec2 t, t_cone *cone);
double	cone_normal(t_vec3 cp, t_vec3 rd, t_cone *cone);
void	init_cone(char **line, t_cone *cone);
t_vec3	cocolor(double *mint, t_vec3 *p, t_vec3 *n, t_cone co);

#endif