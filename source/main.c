/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:06:14 by caugusta          #+#    #+#             */
/*   Updated: 2021/05/13 02:16:33 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(void)
{
	t_data	*img;
	t_vec2	*uv;
	t_vec3	*rayOrigin;
	t_vec3	*rayDirection;

	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, 1920, 1080, "miniRT");
	img->img = mlx_new_image(img->mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	rayOrigin = new_vec3(-5.0, 0.0, 0.0);
	rayDirection = vec3_norm();
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	mlx_key_hook(img->win, ft_close, &img);
	mlx_loop(img->mlx);
	return (0);
}
