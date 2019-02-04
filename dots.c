/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 01:48:30 by kykim             #+#    #+#             */
/*   Updated: 2018/09/18 18:02:57 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dot	**make_dots(int *x, int *y, int *z, int num)
{
	int		i;
	t_dot	**dots;

	dots = malloc(sizeof(t_dot *) * (num + 1));
	i = 0;
	while (i < num)
	{
		dots[i] = malloc(sizeof(t_dot));
		dots[i]->x = x[i];
		dots[i]->y = y[i];
		dots[i]->z = z[i];
		i++;
	}
	dots[i] = NULL;
	return (dots);
}

t_map	*set_dots(t_map *map, char *filename, int interval, int move[2])
{
	int		*x;
	int		*y;
	int		*z;
	t_dot	**dots;

	x = x_value(map->x, map->y, interval, move[0]);
	y = y_value(map->x, map->y, interval, move[1]);
	z = z_value(filename, map->x * map->y, interval);
	dots = make_dots(x, y, z, map->x * map->y);
	map->dots = dots;
	free(x);
	free(y);
	free(z);
	return (map);
}
