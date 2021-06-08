/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   123.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 22:47:08 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/08 18:10:45 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <math.h>

t_vec	at(t_vec orig, t_vec dir, double t)
{
	return (v_add(orig, v_mul_n(dir, t)));
}

t_vec	ray_color(t_vec orig, t_vec dir)
{
	t_vec sphere = {0, 0, -1};
	double t = hit_sphere(sphere, 0.5, orig, dir);
	if (t > 0.0)
	{
		t_vec N = unit_vector(v_sub(at(orig, dir, t), sphere));
		t_vec color;
		color.x = N.x + 1;
		color.y = N.y + 1;
		color.z = N.z + 1;

		return (v_mul_n(color, 0.5));

	}
//	t_vec sphere_color = {1, 0, 0};
//	if (hit_sphere(sphere, 0.5, orig, dir))
//		return (sphere_color);
	t_vec unit_direction = unit_vector(dir);
	t = 0.5 * (unit_direction.y + 1.0);
	t_vec a= make_v(1.0);
	t_vec b; b.x = 0.5; b.y = 0.7; b.z = 1.0;
	return (v_add(v_mul_n(a, 1.0 - t), v_mul_n(b, t)));
}

#include <stdio.h>

int	main()
{
	// Image
	const double	aspect_ratio = 16.0 / 9.0;
	const int	image_width = 400;
	const int	image_height = image_width / aspect_ratio;

	// Start mlx
	t_mlx	*app;
	if (!(app = (t_mlx*)malloc(sizeof(t_mlx))))
		return (-1);
	app->mlx = mlx_init();
	app->win = mlx_new_window(app->mlx, 800, 600, "raytracer");
	app->img = mlx_new_image(app->mlx, image_width, image_height);
	app->addr = (int *)mlx_get_data_addr(app->img, &app->bits_per_pixel, &app->line_length, &app->endian);


	// Camera
	double	viewport_height = 2.0;
	double	viewport_width = aspect_ratio * viewport_height;
	double	focal_length = 1.0;

	t_vec	origin = {0,0,0};
	t_vec	horizontal = {viewport_width, 0, 0};
	t_vec	vertical = {0, viewport_height, 0};
	t_vec	any = {0, 0, focal_length};
	t_vec	lower_left_corner = v_sub(origin, v_add(v_add(v_div(horizontal, 2), v_div(vertical, 2)), any));

	// Render

	int jj = 0;
	int j = image_height - 1;
	while (j >= 0 && jj < image_height)
	{
		int i = 0;
		while (i < image_width)
		{

			double u = (double)i / (image_width - 1);
			double v = (double)j / (image_height - 1);

			t_vec a = origin;
			t_vec b = v_add(lower_left_corner, v_add(v_mul_n(horizontal, u), v_mul_n(v_sub(vertical, origin), v)));
			t_vec pixel_color = ray_color(a, b);
			write_color(app, pixel_color);
			mlx_pixel_put(app->mlx, app->win, i, jj, app->int_color);
//			app->data[jj * 400 + i] = app->int_color;

			++i;
		}
		--j;
		++jj; //예제의 점 찍히는 순서를 똑같이 하려고 jj를 따로 만들었음..
	}
//	mlx_put_image_to_window (app->mlx_ptr, app->win_ptr, app->img_ptr, 0, 0);
	mlx_loop(app->mlx);
}
