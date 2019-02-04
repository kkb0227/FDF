/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 02:02:04 by kykim             #+#    #+#             */
/*   Updated: 2018/09/18 18:20:43 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	x_plus(t_param *param)
{
	mlx_clear_window(param->map->mlx_ptr, param->map->win_ptr);
	param->move[0] += 20;
	free_dots(param);
	param->map = set_dots(param->map, param->filenamae,
	param->map->interval, param->move);
	rotate(param->map);
	draw(param->map);
}

void	x_minus(t_param *param)
{
	mlx_clear_window(param->map->mlx_ptr, param->map->win_ptr);
	param->move[0] -= 20;
	free_dots(param);
	param->map = set_dots(param->map, param->filenamae,
	param->map->interval, param->move);
	rotate(param->map);
	draw(param->map);
}

void	y_plus(t_param *param)
{
	mlx_clear_window(param->map->mlx_ptr, param->map->win_ptr);
	param->move[1] += 20;
	free_dots(param);
	param->map = set_dots(param->map, param->filenamae,
	param->map->interval, param->move);
	rotate(param->map);
	draw(param->map);
}

void	y_minus(t_param *param)
{
	mlx_clear_window(param->map->mlx_ptr, param->map->win_ptr);
	param->move[1] -= 20;
	free_dots(param);
	param->map = set_dots(param->map, param->filenamae,
	param->map->interval, param->move);
	rotate(param->map);
	draw(param->map);
}
