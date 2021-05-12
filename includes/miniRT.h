/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 23:04:54 by caugusta          #+#    #+#             */
/*   Updated: 2021/05/12 21:28:46 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "libft.h"
# include "vec2_utils.h"
# include "vec3_utils.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
	void	*img;
	void	*mlx;
	void	*win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vec3
{
	float		x;
	float		y;
	float		z;
	double		direction_x;
	double		direction_y;
	double		direction_z;
}				t_vec3;

typedef struct s_vec2
{
	float		x;
	float		y;
	double		direction_x;
	double		direction_y;
}				t_vec2;

// typedef struct s_cam
// {
// 	float		x;
// 	float		y;
// 	float		z;
// }				t_cam;

// typedef struct s_scene
// {
	
// }				t_scene

#endif
