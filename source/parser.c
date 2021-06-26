/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 19:04:59 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/26 23:57:03 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_scene(void)
{
	g_scene.width = 1920;
	g_scene.height = 1080;
	g_scene.aspect_ratio = 16.0 / 9.0;
	g_scene.vup = new_vec3(0.0, 1.0, 0.0);
	init_mlx(&g_scene.mlx, g_scene.width, g_scene.height);
	g_scene.alight.count = 0;
	g_scene.light.count = 0;
	g_scene.cam.count = 0;
	g_scene.sp = 0;
	g_scene.pl = 0;
	g_scene.cy = 0;
}

void	pars(int argc, char **argv)
{
	int		fd;
	int		n;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	n = get_next_line(fd, &line);
	init_scene();
	while (n > 0)
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
			// init_cy(line);
		n = get_next_line(fd, &line);
	}
	if (n < 0)
		exit_err(1);
}

void	init_cam(char **line, t_cam *cam, double aspect, t_vec3 vup)
{
	double	half_height;
	double	half_width;
	char	*keepline;

	if (cam->count > 0)
		exit_err(6);
	keepline = *line;
	cam->ro = pars_vec3(line);
	cam->rd = pars_vec3_norm(line);
	cam->FOV = ft_atof(line);
	half_height = tan(cam->FOV / 2);
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
	light->ro = pars_vec3(line);
	light->power = ft_atof(line);
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
	alight->power = ft_atof(line);
	alight->color = vec3_mulS(pars_vec3_color(line), alight->power);
	alight->count += 1;
	free (keepline);
	*line = NULL;
}
