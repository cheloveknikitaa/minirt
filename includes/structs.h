#ifndef STRUCTS_H
# define STRUCTS_H

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

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

typedef struct s_scene
{
	t_data	*mlx;
	t_list	*camera;
	t_list	*alignt;
	t_list	*light;
	t_list	*sphere;
	t_list	*plane;
	t_list	*cylinder;
	t_list	*cone;
}				t_scene;

typedef struct s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

typedef struct s_alight
{
	double		power;
	t_vec3		color;
}				t_alight;

typedef struct s_light
{
	t_vec3		ro;
	double		power;
	t_vec3		color;
}				t_light;

typedef struct s_camera
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
}				t_camera;

typedef struct s_plane
{
	t_vec3		ro;
	t_vec3		n;
	t_vec3		color;
}				t_plane;

typedef struct s_result
{
	t_vec3		color;
	t_vec3		n;
	t_vec3		p;
	double		mint;
}				t_result;
#endif