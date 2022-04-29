/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:43:29 by caugusta          #+#    #+#             */
/*   Updated: 2021/07/05 10:37:02 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_UTILS_H
# define PLANE_UTILS_H
# include "miniRT.h"

typedef struct s_plane
{
	t_vec3		ro;
	t_vec3		n;
	t_vec3		color;
	t_vec3		p;
	double		mint;
}				t_plane;

double	plaIntersect(t_vec3 ro, t_vec3 rd, t_plane *pl);
void	init_pl(char **line, t_plane *pl);
t_vec3	plcolor(double *mint, t_vec3 *p, t_vec3 *n, t_plane pl);
void	pl_new_normal(t_plane *pl, double t, t_vec3 ro, t_vec3 rd);

#endif
