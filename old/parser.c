/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 19:04:59 by caugusta          #+#    #+#             */
/*   Updated: 2021/08/10 20:24:31 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	pars(int argc, char **argv)
{
	int		fd;
	int		n;
	char	*line;

	if (argc > 2)
		exit_err(6);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_err(1);
	n = 1;
	while (n > 0)
	{
		n = get_next_line(fd, &line);
		check_line(line);
	}
	if (n < 0 || g_scene.cam.count == 0 || g_scene.light.count == 0 || \
	g_scene.alight.count == 0)
		exit_err(1);
}


typedef struct s_cam
{
	t_vec3	ro;
	t_vec3	rd;
	t_vec3	horizontal;
	t_vec3	vertical;
	t_vec3	w;
	t_vec3	u;
	t_vec3	v;
	t_vec3	lower_left_corner;
	int		FOV;
	int		count;
}				t_cam;

void	init_cam(char **line, t_cam *cam, double aspect, t_vec3 vup)
{
	double	half_height;
	double	half_width;
	char	*keepline;

	if (cam->count > 0)
		exit_err(6);
	keepline = *line;
	*line = *line + 1;
	cam->ro = pars_vec3(line);
	cam->rd = pars_vec3_norm(line);
	cam->FOV = ft_atof(line);
	check_fov(cam->FOV);
	half_height = tan((cam->FOV * M_PI / 180) / 2);
	half_width = aspect * half_height;
	cam->w = vec3_norm(vec3_sub(cam->ro, cam->rd));
	cam->u = vec3_norm(vec3_cross(vup, cam->w));
	cam->v = vec3_cross(cam->w, cam->u);
	cam->lower_left_corner = vec3_sub(vec3_sub(vec3_sub(cam->ro,
					vec3_mulS(cam->u, half_width)),
				vec3_mulS(cam->v, half_height)), cam->w);
	cam->horizontal = vec3_mulS(cam->u, (half_width * 2));
	cam->vertical = vec3_mulS(cam->v, (half_height * 2));
	cam->count += 1;
	free (keepline);
	*line = NULL;
}

void	init_light(char **line, t_light *light)
{
	char	*keepline;

	if (light->count > 0)
		exit_err(6);
	keepline = *line;
	*line = *line + 1;
	light->ro = pars_vec3(line);
	light->power = ft_atof(line);
	if (light->power < 0.0 || light->power > 1.0)
		exit_err(3);
	light->color = vec3_mulS(pars_vec3_color(line), light->power);
	light->count += 1;
	free (keepline);
	*line = NULL;
}

void	init_alight(char **line, t_alight *alight)
{
	char	*keepline;

	if (alight->count > 0)
		exit_err(6);
	keepline = *line;
	*line = *line + 1;
	alight->power = ft_atof(line);
	if (alight->power < 0.0 || alight->power > 1.0)
		exit_err(3);
	alight->color = vec3_mulS(pars_vec3_color(line), alight->power);
	alight->count += 1;
	free (keepline);
	*line = NULL;
}

void	check_line(char *line)
{
	if (line[0] == 'A')
		init_alight(&line, &g_scene.alight);
	else if (line[0] == 'C')
		init_cam(&line, &g_scene.cam, g_scene.aspect_ratio, g_scene.vup);
	else if (line[0] == 'L')
		init_light(&line, &g_scene.light);
	else if (line[0] == 'p' && line[1] == 'l')
		init_pl(&line, &g_scene.plane[g_scene.pl]);
	else if (line[0] == 's' && line[1] == 'p')
		init_sphere(&line, &g_scene.sphere[g_scene.sp]);
	else if (line[0] == 'c' && line[1] == 'y')
		init_cy(&line, &g_scene.cylinder[g_scene.cy]);
	else if (line[0] == 'c' && line[1] == 'o')
		init_cone(&line, &g_scene.cone[g_scene.co]);
	else if (line[0] == '#' || line[0] == '\0')
		free(line);
	else
		exit_err(1);
}
