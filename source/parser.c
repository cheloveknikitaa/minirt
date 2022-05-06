#include "miniRT.h"

void	parser(int argc, const char **argv, t_scene *scene)
{
	int		fd;
	int		n;
	char	*line;

	if (argc != 2 || (argv[1] && ft_strnstr(argv[1], ".rt", 4)))
		err_exit("Incorrect arguments try \"./miniRT *.rt\"", 1);
	fd = ft_open(argv[1], O_RDONLY);
	n = 1;
	scene = init_scene();
	while (n > 0)
	{
		n = get_next_line(fd, &line);
		check_line(line, scene);
		free(line);
	}
	if (n < 0)
		err_exit("gnl failed!", 1);
}

void	check_line(char *line, t_scene *scene)
{
	if (line == NULL)
		err_exit("Malloc Error", 1);
	if (ft_strncmp(line, "A", 1) == 0 && ft_lstsize(scene->alignt) < 1)
		ft_lstadd_back(&(scene->alignt), init_alight(line + 1));
	else if (ft_strncmp(line, "C", 1) && ft_lstsize(scene->camera) < 1)
		ft_lstadd_back(&(scene->camera), init_camera(line + 1));
	else if (ft_strncmp(line, "L", 1) && ft_lstsize(scene->light < 1))
		ft_lstadd_back(&(scene->light), init_light(line + 1));
	else if (ft_strncmp(line, "pl", 2))
		ft_lstadd_back(&(scene->plane), init_plane(line));
	// else if (ft_strncmp(line, "sp", 2))
	// 	ft_lstadd_back(&(scene->sphere), init_sphere(line));
	// else if (ft_strncmp(line, "cy", 2))
	// 	ft_lstadd_back(&(scene->cylinder), init_cylinder(line));
	// else if (ft_strncmp(line, "co", 2))
	// 	ft_lstadd_back(&(scene->cone), init_cone(line));
	else if (line[0] == '#' || line[0] == '\0')
		;
	else
		exit_err(1);
}

t_list	*init_alight(char *line)
{
	t_list		*new;
	t_alight	*alight;

	alight = ft_malloc(sizeof(t_alight));
	alight->power = ft_atof(&line);
	if (alight->power < 0.0 || alight->power > 1.0)
		exit_err(3);
	alight->color = vec3_mulS(pars_vec3_color(line), alight->power);
	new = ft_lstnew(alight);
	if (new == NULL)
		err_exit("Malloc Error", 1);
	return (new);
}

t_list	*init_camera(char *line)
{
	t_camera	*camera;
	t_list		*new;

	camera = ft_malloc(sizeof(t_camera));
	camera->ro = pars_vec3(line);
	camera->rd = pars_vec3_norm(line);
	camera->FOV = ft_atof(line);
	check_fov(camera->FOV);
	calc_camera(camera);
	new = ft_lstnew(camera);
	if (new == NULL)
		err_exit("Malloc Error", 1);
	return(new);
}

void	calc_camera(t_camera *camera)
{
	double		half_height;
	double		half_width;

	half_height = tan((camera->FOV * M_PI / 180) / 2);
	half_width = ASPECT * half_height;
	camera->w = vec3_norm(vec3_sub(camera->ro, camera->rd));
	camera->u = vec3_norm(vec3_cross(new_vec3(0.0, 1.0, 0.0), camera->w));
	camera->v = vec3_cross(camera->w, camera->u);
	camera->lower_left_corner = vec3_sub(vec3_sub(vec3_sub(camera->ro,
					vec3_mulS(camera->u, half_width)),
				vec3_mulS(camera->v, half_height)), camera->w);
	camera->horizontal = vec3_mulS(camera->u, (half_width * 2));
	camera->vertical = vec3_mulS(camera->v, (half_height * 2));
}

t_list	*init_light(char *line)
{
	t_list		*new;
	t_light		*light;

	light = ft_malloc(sizeof(t_light));
	light->ro = pars_vec3(line);
	light->power = ft_atof(&line);
	if (light->power < 0.0 || light->power > 1.0)
		exit_err(3);
	light->color = vec3_mulS(pars_vec3_color(line), light->power);
	new = ft_lstnew(light);
	if (new == NULL)
		err_exit("Malloc Error", 1);
	return (new);
}

t_list	*init_plane(char *line)
{
	t_list		*new;
	t_plane		*plane;

	plane = ft_malloc(sizeof(t_plane));
	plane->ro = pars_vec3(line);
	plane->n = pars_vec3_norm(line);
	plane->color = pars_vec3_color(line);
	new = ft_lstnew(plane);
	if (new == NULL)
		err_exit("Malloc Error", 1);
	return (new);
}
