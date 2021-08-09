/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita <nikita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:55:03 by caugusta          #+#    #+#             */
/*   Updated: 2021/08/02 14:43:09 by nikita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	plaIntersect(t_vec3 ro, t_vec3 rd, t_plane *pl)
{
	double	d;
	double	t;

	d = -vec3_dot(pl->ro, pl->n);
	t = -((vec3_dot(ro, pl->n) + d) / (vec3_dot(rd, pl->n)));
	if (t >= 0)
	{
		pl_new_normal(pl, t, ro, rd);
		return (t);
	}
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

void	pl_new_normal(t_plane *pl, double t, t_vec3 ro, t_vec3 rd)
{
	pl->mint = t;
	pl->p = vec3_add(ro, vec3_mulS(rd, pl->mint - 0.001));
}

t_vec3	plcolor(double *mint, t_vec3 *p, t_vec3 *n, t_plane pl)
{
	*mint = pl.mint;
	*p = pl.p;
	*n = pl.n;
	return (pl.color);
}
