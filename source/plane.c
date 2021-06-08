/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:55:03 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/06 18:14:41 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	plaIntersect(t_vec3 ro, t_vec3 rd, t_plane pl)
{
	pl.ro = vec3_norm(pl.ro);
	return (-(vec3_dot(ro, pl.ro) + 1.0) / vec3_dot(rd, pl.ro));
}
