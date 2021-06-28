/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:55:03 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/28 23:08:04 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// double	plaIntersect(t_vec3 ro, t_vec3 rd, t_plane *pl)
// {
// 	// double	r;
// 	// double	t;
// 	// double	d;
// 	// double	a;

// 	// d = vec3_dot(rd, pl->n);
// 	// if (d < DBL_EPSILON && d > -DBL_EPSILON)
// 	// 	return (0);
// 	// a = vec3_dot(pl->ro, pl->n);
// 	// r = -(pl->n.x * pl->ro.x) - (pl->n.y * \
// 	// 	pl->ro.y) - (pl->n.z * pl->ro.z);
// 	// r = (pl->ro.x * ro.x + pl->ro.y * ro.y + pl->ro.z * ro.z + r);
// 	// r = r / vec3_lenght(pl->ro);
// 	// if (r < 0)
// 	// 	r = -r;
// 	// t = (r - a) / d;
// 	// return (t);


// }

double	plaIntersect(t_vec3 ro, t_vec3 rd, t_plane pl)
{
	double	d;
	double	t;

	d = -vec3_dot(pl.ro, pl.n);
	t = -((vec3_dot(ro, pl.n) + d) / (vec3_dot(rd, pl.n)));
	if (t >= 0)
		return (t);
	return (-1.0);
}

void	init_pl(char **line, t_plane *pl)
{
	char	*linekeep;

	linekeep = *line;
	*line = *line + 2;
	pl->ro = pars_vec3(line);
	pl->n = pars_vec3_norm(line);
	pl->color = rgb_to_xyz(pars_vec3_color(line));
	g_scene.pl += 1;
	free (linekeep);
	*line = NULL;
}
