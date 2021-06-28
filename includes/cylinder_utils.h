/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 00:39:49 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/29 00:45:30 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_UTILS_H
# define CYLINDER_UTILS_H
# include "miniRT.h"

typedef struct s_cylinder
{
	t_vec3		coord;
	t_vec3		n;
	double		di;
	double		height;
	t_vec3		color;
}				t_cylinder;

#endif