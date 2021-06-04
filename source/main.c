/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:06:14 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/04 11:47:27 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_scene		*g_scene;

void	init_sphere(t_sphere *sphere);
void	init_mlx(t_data *mlx, int width, int height);
void	init_cam(t_cam *cam, float aspect, t_vec3 *vup);
void	init_light(t_light *light, t_alight *alight);
void	pars(void);
t_vec3	*cast_ray(t_vec3 *ro, t_vec3 *rd);
t_vec3	*get_ray(float u, float v);


void	init_sphere(t_sphere *sphere)
{
	sphere = malloc(sizeof(t_sphere));
	sphere->center = new_vec3(0.0, 0.0, 20.6);	// pars
	sphere->ra = 12.6 / 2;						// pars
	sphere->color = new_vec3(10, 0, 255);		// pars
	sphere->next = NULL;						// pars
}

	// start mlx
void	init_mlx(t_data *mlx, int width, int height)
{
	mlx = malloc(sizeof(t_data));
//	if (mlx == NULL)
//		exit ;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, width, height, "miniRT");
	mlx->img = mlx_new_image(mlx->mlx, width, height);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
}

	// init cam
void	init_cam(t_cam *cam, float aspect, t_vec3 *vup)
{
	float	half_height;
	float	half_width;

	cam = malloc(sizeof(t_cam));
	cam->ro = new_vec3(-50.0, 0, 20);	// pars
	cam->rd = new_vec3(0, -0.3, 0.7);	// pars
	cam->FOV = 70;						// pars
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
}

	// init lights
void	init_light(t_light *light, t_alight *alight)
{
	light = malloc(sizeof(t_light));
	light->ro = new_vec3(-40.0, 50.0, 0.0);		// pars
	light->power = 0.6;							// pars
	light->color = new_vec3(10, 0, 255);		// pars
	alight = malloc(sizeof(t_alight));
	alight->power = 0.2;						// pars
	alight->color = new_vec3(255, 255, 255);	// pars
}

	//pars
void	pars(void)
{
	g_scene = malloc(sizeof(t_scene));
	g_scene->width = 1920;
	g_scene->height = 1080;
	g_scene->aspect_ratio = 16.0 / 9.0;
	g_scene->vup = new_vec3(0.0, 1.0, 0.0);
	init_mlx(g_scene->mlx, g_scene->width, g_scene->height);
	init_cam(g_scene->cam, g_scene->aspect_ratio, g_scene->vup);
	init_light(g_scene->light, g_scene->alight);
	init_sphere(g_scene->sphere);
}

t_vec3	*cast_ray(t_vec3 *ro, t_vec3 *rd)
{
	t_vec2	*it;
	t_vec3	*itPos;
	float	diffuse;

	it = sphIntersect(ro, rd, g_scene->sphere->ra);
	if (it->x < 0.0)
		return (new_vec3(0.0, 0.0, 0.0));
	itPos = vec3_add(ro, vec3_mulS(rd, it->x));
	diffuse = vec3_dot(g_scene->light->ro, itPos);
	return (new_vec3(diffuse, diffuse, diffuse));
}

t_vec3	*get_ray(float u, float v)
{
	t_cam	*cam;
	t_vec3	*ray;

	cam = g_scene->cam;
	ray = vec3_add(cam->lower_left_corner,
			vec3_add(vec3_mulS(cam->horizontal, u),
				vec3_mulS(vec3_sub(cam->vertical, cam->ro), v)));
	return (ray);
}

int		main(void)
{
	int		mlx_x;
	int		mlx_y;
	int		i;
	float	u;
	float	v;

	pars();
	mlx_x = 0;
	mlx_y = g_scene->height - 1;
	while (mlx_y >= 0 && mlx_x < g_scene->height)
	{
		i = 0;
		while (i < g_scene->width)
		{
			u = (double)i / (g_scene->width - 1);
			v = (double)mlx_y / (g_scene->height - 1);
			write_color(g_scene->mlx, cast_ray(g_scene->cam->ro,
					get_ray(u, v)));
			my_mlx_pixel_put(g_scene->mlx, i, mlx_x, g_scene->mlx->int_color);
			g_scene->mlx->addr[mlx_x + i] = g_scene->mlx->int_color;
			i++;
		}
		mlx_y--;
		mlx_x++;
	}
	// mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_key_hook(g_scene->mlx->win, ft_close, &g_scene->mlx->mlx);
	mlx_loop(g_scene->mlx->mlx);
	return (0);
}
