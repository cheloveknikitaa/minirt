/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 01:24:36 by caugusta          #+#    #+#             */
/*   Updated: 2021/05/29 01:53:10 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H
# include "miniRT.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
float	max(float a, float b);
float	min(float a, float b);

#endif
