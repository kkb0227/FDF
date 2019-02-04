/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:44:56 by kykim             #+#    #+#             */
/*   Updated: 2018/09/18 18:39:45 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "minilibx_macos/mlx.h"
# include "library/ft_libft/libft.h"
# include "library/Get_Next_Line/get_next_line.h"

typedef struct	s_dot
{
	int x;
	int y;
	int z;
}				t_dot;

typedef struct	s_map
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	int		interval;
	t_dot	**dots;
}				t_map;

typedef struct	s_param
{
	t_map	*map;
	char	filenamae[1000];
	int		move[2];
}				t_param;

t_dot			**make_dots(int *x, int *y, int *z, int num);
t_map			*set_dots(t_map *map, char *filename,
int interval, int move[2]);
int				*x_value(int x_num, int y_num, int interval, int k);
int				*y_value(int x_num, int y_num, int interval, int k);
void			free_line_new(char **news, char **line);
void			assign_z(int *z, int i[2], int interval, char **news);
int				*z_value(char *file, int total, int interval);
void			zero_slope(t_dot *a, t_dot *b, void *win_ptr, void *mlx_ptr);
void			assign_factor(double factor[2], t_dot *a, t_dot *b);
void			in_slope(t_dot *a, t_dot *b, void *win_ptr, void *mlx_ptr);
void			out_slope(t_dot *a, t_dot *b, void *win_ptr, void *mlx_ptr);
void			draw_line(t_dot *a, t_dot *b, void *win_ptr, void *mlx_ptr);
int				read_x(int fd, char **line);
int				get_xnum(char *file);
int				get_ynum(char *file);
void			x_plus(t_param *param);
void			x_minus(t_param *param);
void			y_plus(t_param *param);
void			y_minus(t_param *param);
void			print_dots(t_dot **dots,
void *mlx_ptr, void *win_ptr);
void			draw_vertical(t_dot **dots,
int x, void *win_ptr, void *mlx_ptr);
void			draw_horizontal(t_dot **dots,
int x, void *win_ptr, void *mlx_ptr);
void			draw(t_map *map);
void			rotate_z(t_dot *dot);
void			rotate_x(t_dot *dot);
void			rotate_y(t_dot *dot);
void			rotate_total(t_dot **dots, int total);
void			rotate(t_map *map);
void			rotate_total2(t_dot **dots, int total);
void			rotate2(t_map *map);
void			zoom_in(t_param *param);
void			zoom_out(t_param *param);
void			different_projection(t_param *param);
void			free_dots(t_param *param);
void			free_param(t_param *param);
int				key(int keycode, t_param *param);
void			argc_check(int ac);
int				main(int argc, char **argv);
#endif
