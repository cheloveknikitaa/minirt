/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_protect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 22:14:49 by caugusta          #+#    #+#             */
/*   Updated: 2021/06/26 23:52:54 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	check_ending(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if ((line[i] >= 9 && line[i] <= 13) || line[i] == ' ')
			i++;
		else
			exit_err(1);
	}
}

void	check_name(char *argv)
{
	int	i;

	i = -1;
	while (argv[++i] != '\0')
	{
		if (argv[i] == '.')
			break ;
		i++;
	}
	if (argv[i + 1] == 'r')
	{
		if (argv[i + 2] == 't')
		{
			if (argv[i + 3] == '\0')
				return ;
		}
	}
	exit_err(1);
}

void	exit_err(int code)
{
	write(1, "Error\n", 7);
	if (code == 1)
		write(1, "invalid file\n", 14);
	if (code == 2)
		write(1, "invalid color\n", 15);
	if (code == 3)
		write(1, "invalid argument\n", 18);
	if (code == 4)
		write(1, "invalid argument, normal\n", 26);
	if (code == 5)
		write(1, "invalid argument, coordinates\n", 31);
	if (code == 6)
		write(1, "invalid argument, too much argument\n", 37);
	exit (1);
}
