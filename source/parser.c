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
		check_line(line, &scene);
		free(line);
	}
	if (n < 0)
		err_exit("gnl failed!", 1);
}

void	check_line(char *line, t_scene **scene)
{
	if (line == NULL)
		err_exit("Malloc Error", 1);
	if (ft_strncmp(line, "A", 1) == 0 && ft_lstsize((*scene)->alignt) < 1)
		ft_lstadd_back(&(*scene)->alignt, init_alight(line));
	else if (ft_strncmp(line, "C", 1) && ft_lstsize((*scene)->camera) < 1)
		ft_lstadd_back(&(*scene)->camera, init_alight(line));
	else if (ft_strncmp(line, "L", 1) && ft_lstsize((*scene)->light < 1)
		ft_lstadd_back(&(*scene)->light init_alight(line));
	else if (ft_strncmp(line, "pl", 2))
		init_pl(&line, &g_scene.plane[g_scene.pl]);
	else if (ft_strncmp(line, "sp", 2))
		init_sphere(&line, &g_scene.sphere[g_scene.sp]);
	else if (ft_strncmp(line, "cy", 2))
		init_cy(&line, &g_scene.cylinder[g_scene.cy]);
	else if (ft_strncmp(line, "co", 2))
		init_cone(&line, &g_scene.cone[g_scene.co]);
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
	line += 1;
	alight->power = ft_atof(&line);
	if (alight->power < 0.0 || alight->power > 1.0)
		exit_err(3);
	alight->color = vec3_mulS(pars_vec3_color(line), alight->power);
	new = ft_lstnew(alight);
	if (new == NULL)
		err_exit("Malloc Error", 1);
	return (new);
}
