/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 23:04:54 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/16 19:15:31 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "libft.h"
# include "vec2_utils.h"
# include "vec3_utils.h"
# include "mlx_utils.h"
# include "hook_utils.h"
# include "sphere_utils.h"
# include "plane_utils.h"

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# define MAX_REF 8
# define SPEC_STRNG 256.0
# define MAX_DIST 99999.0

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
}				t_light;

typedef struct s_alight
{
	double		power;
	t_vec3		color;
	int			int_color;
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
	t_sphere	sphere[2];
	t_plane		plane;
}				t_scene;

t_scene		g_scene;

void	write_color(t_data *scene, t_vec3 ray);
void	my_mlx_pixel_put(t_data data, int x, int y, int color);
int		ft_close(int keycode, t_data *vars);
t_vec3	ray_color(t_vec3 ro, t_vec3 rd);
t_vec3	mix_color(t_vec3 color1, t_vec3 color2);
t_vec3	rgb_to_Yxy(t_vec3 color);
t_vec3	Yxy_to_rgb(t_vec3 color);
t_vec3	rgb_to_xyz(t_vec3 color);
t_vec3	xyz_to_rgb(t_vec3 color);
double	sphdiffuse(t_vec3 ro, t_vec3 rd, double t, int i);

#endif
