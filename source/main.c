#include "mlx.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

typedef struct s_data
{
	void	*img;
	void	*img1;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
	int		z;
	void	*mlx;
	void	*win;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	render_next_frame(t_data *img)
{
	printf("Hello from key_hook!\n");
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i++ < 100)
	{
		j = 0;
		img->y = img->z;
		while (j++ < 100)
		{
			my_mlx_pixel_put(&img, img->x, img->y, 0x00ff45);
			img->y++;
		}
		img->x++;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img1, 0, 0);
}

int	close(int keycode, t_data *img)
{
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->win);
		exit(0);
	}
}

int	main(void)
{
	// void	*mlx;
	t_data	img;
	// void	*mlx_win;
	int		i;
	int		j;
	int		r;

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, 1280, 720, "yoyo");
	img.img = mlx_new_image(img.mlx, 1280, 720);
	// img.img1 = mlx_new_image(img.mlx, 1280, 720);
	img.y = 400;
	img.z = 400;
	img.x = 200;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	j = 0;
	r = 20;
	i = 0;
	while (i < 2 * r)
	{
		while (j < 2 * r)
		{
			my_mlx_pixel_put(&img, img.x, img.y, 0x00ff45);
			img.y++;
			j++;
		}
		img.x++;
		i++;		
		// j = sqrt(i * i + r * r);
		// img.x = i + 40;
		// // img.y = 12 - j;
		// // my_mlx_pixel_put(&img, img.x, img.y, 0x00ff45);
		// img.y = j;
		// i++;

	}

	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_hook(img.win, 2, 1L<<0, close, &img);
	// mlx_hook(img.win, 2, 1L<<0, render_next_frame, &img);
	// mlx_hook(img.win, 18, 1L<<4, close, &img);
	// mlx_hook(img.win, 19, 1L<<5, close, &img);
	// mlx_hook(img.win, 25, 1L<<18, close, &img);
	mlx_loop(img.mlx);
}

	// SQUARE

	// while (i++ < 100)
	// {
	// 	j = 0;
	// 	img.y = img.z;
	// 	while (j++ < 100)
	// 	{
	// 		my_mlx_pixel_put(&img, img.x, img.y, 0x00ff45);
	// 		img.y++;
	// 	}
	// 	img.x++;
	// }

	// TRIANGLE

	// 	while (i++ < 100)
	// {
	// 	j = 0;
	// 	img.y = img.z;
	// 	while (j++ < i - 1)
	// 	{
	// 		my_mlx_pixel_put(&img, img.x, img.y, 0x30df88);
	// 		img.y++;
	// 	}
	// 	// img.z += 1;
	// 	img.x++;
	// }