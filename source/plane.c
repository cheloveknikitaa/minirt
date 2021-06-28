/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:55:03 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/29 00:03:27 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
