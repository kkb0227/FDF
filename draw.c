/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 15:10:03 by kykim             #+#    #+#             */
/*   Updated: 2018/09/18 18:16:11 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zero_slope(t_dot *a, t_dot *b, void *win_ptr, void *mlx_ptr)
{
	int x;

	if (a->y >= b->y)
	{
		x = b->y;
		while (x < a->y)
		{
			x++;
			mlx_pixel_put(mlx_ptr, win_ptr, b->x, x, 0xAFAFAF);
		}
	}
	else
	{
		x = a->y;
		while (x < b->y)
		{
			x++;
			mlx_pixel_put(mlx_ptr, win_ptr, a->x, x, 0xAFAFAF);
		}
	}
}

void	assign_factor(double factor[2], t_dot *a, t_dot *b)
{
	factor[0] = (double)(b->y - a->y) / (b->x - a->x);
	factor[1] = (double)a->y - (factor[0] * a->x);
}

void	in_slope(t_dot *a, t_dot *b, void *win_ptr, void *mlx_ptr)
{
	double	factor[2];
	int		new[3];

	assign_factor(factor, a, b);
	new[0] = (a->x <= b->x) ? a->x : b->x;
	if (a->x <= b->x)
	{
		while (new[0]++ < b->x)
		{
			new[1] = factor[0] * new[0] + factor[1];
			new[2] = (ceil(new[1]) - new[1]) < (new[1] - floor(new[1]))
			? ceil(new[1]) : floor(new[1]);
			mlx_pixel_put(mlx_ptr, win_ptr, new[0], new[2], 0xAFAFAF);
		}
	}
	else if (b->x < a->x)
	{
		while (new[0]++ < a->x)
		{
			new[1] = factor[0] * new[0] + factor[1];
			new[2] = (ceil(new[1]) - new[1]) < (new[1] - floor(new[1]))
			? ceil(new[1]) : floor(new[1]);
			mlx_pixel_put(mlx_ptr, win_ptr, new[0], new[2], 0xAFAFAF);
		}
	}
}

void	out_slope(t_dot *a, t_dot *b, void *win_ptr, void *mlx_ptr)
{
	double	factor[2];
	int		new[3];

	assign_factor(factor, a, b);
	new[0] = (a->y <= b->y) ? a->y : b->y;
	if (a->y <= b->y)
	{
		while (new[0]++ < b->y)
		{
			new[1] = (new[0] - factor[1]) / factor[0];
			new[2] = (ceil(new[1]) - new[1]) < (new[1] - floor(new[1]))
			? ceil(new[1]) : floor(new[1]);
			mlx_pixel_put(mlx_ptr, win_ptr, new[2], new[0], 0xAFAFAF);
		}
	}
	else if (b->y < a->y)
	{
		while (new[0]++ < a->y)
		{
			new[1] = (new[0] - factor[1]) / factor[0];
			new[2] = (ceil(new[1]) - new[1]) < (new[1] - floor(new[1]))
			? ceil(new[1]) : floor(new[1]);
			mlx_pixel_put(mlx_ptr, win_ptr, new[2], new[0], 0xAFAFAF);
		}
	}
}

void	draw_line(t_dot *a, t_dot *b, void *win_ptr, void *mlx_ptr)
{
	double	slope;
	double	yzp;

	if (a->x == b->x)
	{
		zero_slope(a, b, win_ptr, mlx_ptr);
		return ;
	}
	slope = (double)(b->y - a->y) / (b->x - a->x);
	yzp = (double)a->y - (slope * a->x);
	if (slope >= -1 && slope <= 1)
		in_slope(a, b, win_ptr, mlx_ptr);
	else if (slope < -1 || slope > 1)
		out_slope(a, b, win_ptr, mlx_ptr);
}
