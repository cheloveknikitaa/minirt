/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:06:14 by caugusta          #+#    #+#             */
/*   Updated: 2021/05/29 06:19:02 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int			g_width;
int			g_height;
float		g_aspect_ratio;
t_data		*g_scene;
t_cam		*g_cam;
t_sphere	*g_sphere;
t_light		*g_light;
t_alight	*g_alight;

	//pars
void	pars(void)
{
	g_width = 1920;
	g_height = 1080;
	g_aspect_ratio = 16.0 / 9.0;

	g_cam = malloc(sizeof(t_cam));
	g_cam->ro = new_vec3(-50.0, 0, 20);
	g_cam->rd = new_vec3(0, 0, 1);
	g_cam->FOV = 70;

	// g_cam->viewport_height = 2.0;
	// g_cam->viewport_width = g_aspect_ratio * g_cam->viewport_width;
	// g_cam->focal_lenght = 1.0;
	// g_cam->ro = new_vec3(0, 0, 0);
	// g_cam->horizontal = new_vec3(g_cam->viewport_width, 0, 0);
	// g_cam->vertical = new_vec3(0, g_cam->viewport_height, 0);
	// g_cam->any = new_vec3(0, 0, g_cam->focal_lenght);
	// g_cam->lower_left_corner = vec3_sub(g_cam->ro, vec3_add(vec3_add(vec3_div(g_cam->horizontal, 2), vec3_div(g_cam->vertical, 2)), any));

	g_sphere = malloc(sizeof(t_sphere));
	g_sphere->center = new_vec3(0.0, 0.0, 20.6);
	g_sphere->ra = 12.6 / 2;
	g_sphere->color = new_vec3(10, 0, 255);
	g_sphere->next = NULL;

	g_light = malloc(sizeof(t_light));
	g_light->ro = new_vec3(-40.0, 50.0, 0.0);
	g_light->power = 0.6;
	g_light->color = new_vec3(10, 0, 255);

	g_alight = malloc(sizeof(t_alight));
	g_alight->power = 0.2;
	g_alight->color = new_vec3(255, 255, 255);
}

	// start mlx
t_data	*init_mlx(void)
{
	t_data	*g_scene;

	g_scene = malloc(sizeof(t_data));
	if (g_scene == NULL)
		exit ;
	g_scene->mlx = mlx_init();
	g_scene->win = mlx_new_window(g_scene->mlx, g_width, g_height, "miniRT");
	g_scene->img = mlx_new_image(g_scene->mlx, g_width, g_height);
	g_scene->addr = mlx_get_data_addr(g_scene->img, &g_scene->bits_per_pixel,
			&g_scene->line_length, &g_scene->endian);
}

int	main(void)
{
	int		mlx_x;
	int		mlx_y;
	int		i;
	float	u;
	float	v;

	pars();
	g_scene = init_mlx();
	mlx_x = 0;
	mlx_y = g_height - 1;
	while (mlx_y >= 0 && mlx_x < g_height)
	{
		i = 0;
		while (i < g_width)
		{
			u = (double)i / (g_width - 1);
			v = (double)mlx_y / (g_height - 1);
			
		}
	}
	my_mlx_pixel_put(g_scene, i, jj, g_scene->int_color);
	mlx_put_image_to_window(g_scene->mlx, g_scene->win, g_scene->img, 0, 0);
	mlx_key_hook(g_scene->win, ft_close, &g_scene);
	mlx_loop(g_scene->mlx);
	return (0);
}
