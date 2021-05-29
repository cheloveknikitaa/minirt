/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 23:04:54 by caugusta          #+#    #+#             */
/*   Updated: 2021/05/29 06:13:55 by caugusta         ###   ########.fr       */
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

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# define MAX_REF 8
# define MAX_DIST 99999.0

typedef struct s_data
{
	void	*img;
	void	*mlx;
	void	*win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_vec3	*color;
	int		int_color;
}				t_data;

typedef struct s_light
{
	t_vec3		*ro;
	double		power;
	t_vec3		*color;
	int			int_color;
}				t_light;

typedef struct s_alight
{
	double		power;
	t_vec3		*color;
	int			int_color;
}				t_alight;

typedef struct s_cam
{
	t_vec3	*rd;
	float	viewport_height;
	float	viewport_width;
	float	focal_lenght;
	t_vec3	*ro;
	t_vec3	*horizontal;
	t_vec3	*vertical;
	t_vec3	*any;
	t_vec3	*lower_left_corner;
	int		FOV;
}				t_cam;

#endif
