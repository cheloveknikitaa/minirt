/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 10:45:06 by caugusta          #+#    #+#             */
/*   Updated: 2021/08/10 17:43:47 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_mlx(t_data *mlx, int width, int height)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, width, height, "miniRT");
	mlx->img = mlx_new_image(mlx->mlx, width, height);
	mlx->addr = (int *)mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
}

int	main(int argc, char **argv)
{
	int		j;
	int		i;

	if (argc != 2)
		exit (0);
	check_name(argv[1]);
	pars(argc, argv);
	j = 0;
	while (j < g_scene.height)
	{
		i = 0;
		while (i < g_scene.width)
		{
			write_color(&g_scene.mlx, ray_color(g_scene.cam.ro,
					get_ray(i, j), 0));
			mlx_pixel_put(g_scene.mlx.mlx, g_scene.mlx.win, i,
				j, g_scene.mlx.int_color);
			i++;
		}
		j++;
	}
	mlx_key_hook(g_scene.mlx.win, ft_close, &g_scene.mlx.mlx);
	mlx_hook(g_scene.mlx.win, 17, 1L << 0, ft_close_win, g_scene.mlx.mlx);
	mlx_loop(g_scene.mlx.mlx);
	return (0);
}
