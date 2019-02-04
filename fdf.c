/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 18:52:08 by kykim             #+#    #+#             */
/*   Updated: 2018/09/18 18:27:19 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_dots(t_param *param)
{
	int i;

	i = 0;
	while (param->map->dots[i])
	{
		free(param->map->dots[i]);
		i++;
	}
	free(param->map->dots);
}

void	free_param(t_param *param)
{
	free_dots(param);
	free(param->map);
	free(param);
}

int		key(int keycode, t_param *param)
{
	if (keycode == 53)
	{
		free_param(param);
		mlx_destroy_window(param->map->mlx_ptr, param->map->win_ptr);
		exit(0);
	}
	else if (keycode == 0)
		zoom_in(param);
	else if (keycode == 1)
		zoom_out(param);
	else if (keycode == 124)
		x_plus(param);
	else if (keycode == 123)
		x_minus(param);
	else if (keycode == 125)
		y_plus(param);
	else if (keycode == 126)
		y_minus(param);
	else if (keycode == 2)
		different_projection(param);
	return (0);
}

void	argc_check(int ac)
{
	if (ac != 2)
	{
		ft_putstr("Error!\nPut only 1 parameter : map\n");
		exit(0);
	}
}

int		main(int argc, char **argv)
{
	t_map	*map;
	t_param	*param;
	int		move[2];

	argc_check(argc);
	move[0] = 0;
	move[1] = 0;
	param = malloc(sizeof(t_param));
	map = malloc(sizeof(t_map));
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, 1800, 1200, "test");
	map->x = get_xnum(argv[1]);
	map->y = get_ynum(argv[1]);
	map->interval = (1200 / map->x) < (800 / map->y) ?
	(1200 / map->x) : (800 / map->y);
	map = set_dots(map, argv[1], map->interval, move);
	param->map = map;
	param->move[0] = 0;
	param->move[0] = 0;
	ft_strcpy(param->filenamae, argv[1]);
	rotate(map);
	draw(map);
	mlx_key_hook(map->win_ptr, key, param);
	mlx_loop(map->mlx_ptr);
}
