/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:06:14 by caugusta          #+#    #+#             */
/*   Updated: 2021/05/13 15:41:34 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(void)
{
	t_data	*img;
	t_vec2	*pixel;
	t_vec3	*rayOrigin;
	t_vec3	*rayDirection;
	int		mlx_x;
	int		mlx_y;
	int		samples;
	t_vec3	*col;
	

	mlx_x = 0;
	mlx_y = 0;
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, 1920, 1080, "miniRT");
	img->img = mlx_new_image(img->mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	pixel->x = ((2 * mlx_x) - 1920) / 1080;
	pixel->y = ((2 * mlx_y) - 1920) / 1080;
	rayOrigin = new_vec3(-5.0, 0.0, 0.0);
	rayDirection = vec3_norm(new_vec3(1.0, pixel->x, pixel->y));
	col = new_vec3(0.0, 0.0, 0.0);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	mlx_key_hook(img->win, ft_close, &img);
	mlx_loop(img->mlx);
	return (0);
}
