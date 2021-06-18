/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:43:29 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/18 17:04:06 by caugusta         ###   ########.fr       */
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
}				t_plane;

double	plaIntersect(t_vec3 ro, t_vec3 rd, t_plane *pl);
double	plaIntersect1(t_vec3 ro, t_vec3 rd, t_plane pl);

#endif
