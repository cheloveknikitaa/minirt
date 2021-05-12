/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 23:04:54 by caugusta          #+#    #+#             */
/*   Updated: 2021/05/11 23:37:54 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "libft.h"

typedef struct s_vec
{
	float		x;
	float		y;
	float		z;
	double		direction_x;
	double		direction_y;
	double		direction_z;
}				t_vec;

typedef struct s_cam
{
	float		x;
	float		y;
	float		z;
}				t_cam;

typedef struct s_scene
{
	
}				t_scene

#endif
