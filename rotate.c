/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:05:15 by kykim             #+#    #+#             */
/*   Updated: 2018/09/18 18:22:41 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_z(t_dot *dot)
{
	int x;
	int y;

	x = dot->x;
	y = dot->y;
	dot->x = x * cos(4 * M_PI / 180) - sin(4 * M_PI / 180) * y;
	dot->y = x * sin(4 * M_PI / 180) + cos(4 * M_PI / 180) * y;
}

void	rotate_x(t_dot *dot)
{
	int y;
	int z;

	y = dot->y;
	z = dot->z;
	dot->y = y * cos(3 * M_PI / 180) - sin(3 * M_PI / 180) * z;
	dot->z = y * sin(3 * M_PI / 180) + cos(3 * M_PI / 180) * z;
}

void	rotate_y(t_dot *dot)
{
	int x;
	int z;

	x = dot->x;
	z = dot->z;
	dot->x = x * cos(3 * M_PI / 180) - sin(3 * M_PI / 180) * z;
	dot->z = x * sin(3 * M_PI / 180) + cos(3 * M_PI / 180) * z;
}

void	rotate_total(t_dot **dots, int total)
{
	int i;

	i = 0;
	while (i < total)
	{
		rotate_z(dots[i]);
		rotate_x(dots[i]);
		rotate_y(dots[i]);
		i++;
	}
}

void	rotate(t_map *map)
{
	rotate_total(map->dots, map->x * map->y);
}
