/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 23:04:54 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/28 22:42:19 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "libft.h"
# include "vec2_utils.h"
# include "vec3_utils.h"
# include "mlx_utils.h"
# include "sphere_utils.h"
# include "plane_utils.h"

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <float.h>
# define MAX_REF 8
# define MAX_OBJ 100
# define SPEC_STRNG 256.0

typedef struct s_data
{
	void	*img;
	void	*mlx;
	void	*win;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_vec3	color;
	int		int_color;
}				t_data;

typedef struct s_light
{
	t_vec3		ro;
	double		power;
	t_vec3		color;
	int			int_color;
	int			count;
}				t_light;

typedef struct s_alight
{
	double		power;
	t_vec3		color;
	int			int_color;
	int			count;
}				t_alight;

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

typedef struct s_scene
{
	int			width;
	int			height;
	double		aspect_ratio;
	t_vec3		vup;
	t_data		mlx;
	t_cam		cam;
	t_alight	alight;
	t_light		light;
	t_sphere	sphere[MAX_OBJ];
	int			sp;
	t_plane		plane[MAX_OBJ];
	int			pl;
	int			cy;
}				t_scene;

t_scene		g_scene;

int		ft_close_win(void);
int		ft_close(int keycode, t_data *vars);
void	check_ending(char *line);
void	check_name(char *argv);
void	exit_err(int code);

// void	my_mlx_pixel_put(t_data data, int x, int y, int color);
// t_vec3	mix_color(t_vec3 color1, t_vec3 color2);
// t_vec3	rgb_to_Yxy(t_vec3 color);
// t_vec3	Yxy_to_rgb(t_vec3 color);
// t_vec3	xyz_to_rgb(t_vec3 color);

double	ft_atof(char **line);
double	ft_atof2(char **line, int i);

void	init_scene(void);
void	init_mlx(t_data *mlx, int width, int height);
void	pars(int argc, char **argv);
void	init_cam(char **line, t_cam *cam, double aspect, t_vec3 vup);
void	init_light(char **line, t_light *light);
void	init_alight(char **line, t_alight *alight);
void	check_line(char *line);

t_vec3	get_ray(int i, int j);
void	write_color(t_data *scene, t_vec3 ray);
t_vec3	ray_color(t_vec3 ro, t_vec3 rd);
t_vec3	rgb_to_xyz(t_vec3 color);
double	diffuse(t_vec3 p, t_vec3 n, t_vec3 rd);
int		shadow(t_vec3 ro, t_vec3 rd);
void	mix_color_light(t_light *light, t_alight *alight);


#endif
