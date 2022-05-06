#include "miniRT.h"

t_vec3	ray_color(t_vec3 ro, t_vec3 rd)
{
	t_result *min;
	t_result *tmp;

	tmp = plain_intersect();
	if (tmp->mint < DBL_MAX)
		min = tmp;
	
}

t_result *plain_intersect(t_vec3 ro, t_vec3 rd, t_list *plane)
{
	double	d;
	double	t;
	t_plane	*pl;
	t_result res;

	pl = (t_plane *)plane->content;
	d = -vec3_dot(pl->ro, pl->n);
	t = -((vec3_dot(ro, pl->n) + d) / (vec3_dot(rd, pl->n)));
	if (t >= 0)
	{
		pl_new_normal(pl, t, ro, rd);
		return (t);
	}
	return (-1.0);
}
