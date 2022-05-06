#ifndef MINIRT_H
# define MINIRT_H

#define ASPECT ((double)16 / (double)9)
#define WIDTH 1920
#define HEIGHT 1080

#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <float.h>
#include "libft.h"
#include "structs.h"

double	max(double a, double b);
double	min(double a, double b);
double	ft_atof(char **line);
// t_vec2	solve_quadratic(double a, double b, double c);

void	parser(int argc, const char **argv, t_scene *scene);
void	check_line(char *line, t_scene *scene);
t_list	*init_alight(char *line);
t_list	*init_camera(char *line);
void	calc_camera(t_camera *camera);
t_list	*init_light(char *line);
t_list	*init_plane(char *line);


t_vec3	vec3_add(t_vec3 a, t_vec3 b);
t_vec3	vec3_sub(t_vec3 a, t_vec3 b);
t_vec3	vec3_mul(t_vec3 a, t_vec3 b);
t_vec3	vec3_mulS(t_vec3 a, double value);
double	vec3_dot(t_vec3 a, t_vec3 b);
double	vec3_lenght(t_vec3 a);
t_vec3	vec3_norm(t_vec3 a);
t_vec3	vec3_reflect(t_vec3 rd, t_vec3 n);
t_vec3	new_vec3(double x, double y, double z);
t_vec3	vec3_div(t_vec3 a, double c);
t_vec3	vec3_cross(t_vec3 a, t_vec3 b);
t_vec3	pars_vec3(char **line);
t_vec3	pars_vec3_color(char **line);
t_vec3	pars_vec3_norm(char **line);
void	check_pars_vec3(double x, double y, double z, int i);

void	exit_err(int code);

#endif