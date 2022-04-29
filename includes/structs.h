#ifndef STRUCTS_H
# define STRUCTS_H

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

typedef struct s_scene
{
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

typedef struct s_cam
{
	t_vec3	ro;
	t_vec3	rd;
	int		FOV;
}				t_cam;



#endif