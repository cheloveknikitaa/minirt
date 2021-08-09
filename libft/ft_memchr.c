/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 18:34:07 by caugusta          #+#    #+#             */
/*   Updated: 2021/08/09 18:34:08 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	unsigned char	*strc;

	strc = (unsigned char *)str;
	while (len > 0)
	{
		if (*strc == (unsigned char)c)
			return ((unsigned char *)strc);
		strc++;
		len--;
	}
	return (0);
}
