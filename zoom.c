/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 01:59:47 by kykim             #+#    #+#             */
/*   Updated: 2018/09/18 18:24:16 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_total2(t_dot **dots, int total)
{
	int i;

	i = 0;
	while (i < total)
	{
		rotate_x(dots[i]);
		rotate_x(dots[i]);
		rotate_x(dots[i]);
		rotate_y(dots[i]);
		i++;
	}
}

void	rotate2(t_map *map)
{
	rotate_total2(map->dots, map->x * map->y);
}

void	zoom_in(t_param *param)
{
	mlx_clear_window(param->map->mlx_ptr, param->map->win_ptr);
	param->map->interval = param->map->interval * 2;
	free_dots(param);
	param->map = set_dots(param->map, param->filenamae,
	param->map->interval, param->move);
	rotate(param->map);
	draw(param->map);
}

void	zoom_out(t_param *param)
{
	mlx_clear_window(param->map->mlx_ptr, param->map->win_ptr);
	if (param->map->interval / 2)
		param->map->interval = param->map->interval / 2;
	free_dots(param);
	param->map = set_dots(param->map, param->filenamae,
	param->map->interval, param->move);
	rotate(param->map);
	draw(param->map);
}

void	different_projection(t_param *param)
{
	mlx_clear_window(param->map->mlx_ptr, param->map->win_ptr);
	free_dots(param);
	param->map = set_dots(param->map, param->filenamae,
	param->map->interval, param->move);
	rotate2(param->map);
	draw(param->map);
}
