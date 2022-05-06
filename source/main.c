#include "miniRT.h"

t_data	*init_mlx(int width, int height)
{
	t_data *mlx;

	mlx = ft_malloc(sizeof(t_data));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, width, height, "miniRT");
	mlx->img = mlx_new_image(mlx->mlx, width, height);
	mlx->addr = (int *)mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
}

int	main(int argc, const char **argv)
{
	t_scene	scene;

	ft_memset(&scene, '\0', sizeof(t_scene));
	parser(argc, argv, &scene);
	scene.mlx = init_mlx(WIDTH, HEIGHT);
	to_window(&scene, 0, 0);
	mlx_key_hook(scene.mlx->win, ft_close, &scene.mlx->mlx);
	mlx_hook(scene.mlx->win, 17, 1L << 0, ft_close_win, scene.mlx->mlx);
	mlx_loop(scene.mlx->mlx);
}

void	to_window(t_scene *scene, int i, int j)
{
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			write_color(&scene.mlx, ray_color(((t_camera *)scene->camera)->ro,
					get_ray(i, j), 0));
			mlx_pixel_put(g_scene.mlx.mlx, g_scene.mlx.win, i,
				j, scene.mlx.int_color);
			i++;
		}
		j++;
	}
}

int	ft_close(int keycode, t_data *vars)
{
	if (keycode == 53 || keycode == 0xFF1B)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);
	}
	return (0);
}

int	ft_close_win(void)
{
	exit (0);
}

void	exit_err(int code)
{
	write(1, "Error\n", 7);
	if (code == 1)
		write(2, "invalid file\n", 14);
	if (code == 2)
		write(2, "invalid color\n", 15);
	if (code == 3)
		write(2, "invalid argument\n", 18);
	if (code == 4)
		write(2, "invalid argument, normal\n", 26);
	if (code == 5)
		write(2, "invalid argument, coordinates\n", 31);
	if (code == 6)
		write(2, "invalid argument, incorrect amount of arguments\n", 49);
	exit (1);
}
