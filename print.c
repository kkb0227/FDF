/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 01:49:40 by kykim             #+#    #+#             */
/*   Updated: 2018/09/18 18:21:52 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_dots(t_dot **dots, void *mlx_ptr, void *win_ptr)
{
	int i;

	i = 0;
	while (dots[i])
	{
		mlx_pixel_put(mlx_ptr, win_ptr, dots[i]->x, dots[i]->y, 0xAFAFAF);
		i++;
	}
}

void	draw_vertical(t_dot **dots, int x, void *win_ptr, void *mlx_ptr)
{
	int i;

	i = 0;
	while (dots[i + 1])
	{
		if ((i % x) != x - 1)
			draw_line(dots[i], dots[i + 1], win_ptr, mlx_ptr);
		i++;
	}
}

void	draw_horizontal(t_dot **dots, int x, void *win_ptr, void *mlx_ptr)
{
	int i;

	i = 0;
	while (dots[i + x])
	{
		draw_line(dots[i], dots[i + x], win_ptr, mlx_ptr);
		i++;
	}
}

void	draw(t_map *map)
{
	draw_vertical(map->dots, map->x, map->win_ptr, map->mlx_ptr);
	draw_horizontal(map->dots, map->x, map->win_ptr, map->mlx_ptr);
}
