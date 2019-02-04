/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 18:02:30 by kykim             #+#    #+#             */
/*   Updated: 2018/09/18 18:12:06 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*x_value(int x_num, int y_num, int interval, int k)
{
	int *x;
	int i;
	int j;

	i = 0;
	x = malloc(sizeof(int) * (x_num * y_num + 1));
	x[x_num * y_num] = '\0';
	while (i < x_num * y_num)
	{
		j = 0;
		while (j < x_num)
		{
			if (i % x_num == j)
				x[i] = 300 + (j * interval) + k;
			j++;
			i++;
		}
	}
	return (x);
}

int		*y_value(int x_num, int y_num, int interval, int k)
{
	int *y;
	int i;
	int j;

	i = 0;
	y = malloc(sizeof(int) * (x_num * y_num + 1));
	y[x_num * y_num] = '\0';
	while (i < x_num * y_num)
	{
		j = 0;
		while (j < y_num)
		{
			if (i / x_num == j)
			{
				y[i] = 200 + (j * interval) + k;
				i++;
			}
			else
				j++;
		}
	}
	return (y);
}

void	free_line_new(char **news, char **line)
{
	free(news);
	free(*line);
}

void	assign_z(int *z, int i[2], int interval, char **news)
{
	free(news[i[0]]);
	z[i[1]] = z[i[1]] * interval * 1.3;
	i[0]++;
	i[1]++;
}

int		*z_value(char *file, int total, int interval)
{
	int		*z;
	char	**line;
	int		fd;
	char	**new;
	int		i[2];

	i[1] = 0;
	line = malloc(sizeof(char *));
	z = malloc(sizeof(int) * (total + 1));
	z[total] = '\0';
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, line))
	{
		i[0] = 0;
		new = ft_strsplit(*line, ' ');
		while (new[i[0]])
		{
			z[i[1]] = ft_atoi(new[i[0]]);
			assign_z(z, i, interval, new);
		}
		free_line_new(new, line);
	}
	free(line);
	close(fd);
	return (z);
}
