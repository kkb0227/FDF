/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 01:47:18 by kykim             #+#    #+#             */
/*   Updated: 2018/09/18 18:18:26 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	read_x(int fd, char **line)
{
	int		i;
	int		x;
	char	**new;

	i = 0;
	x = get_next_line(fd, line);
	if (x < 0 || line[0] == NULL)
	{
		ft_putstr("Wrong File! : check your file\n");
		exit(0);
	}
	else
	{
		new = ft_strsplit(*line, ' ');
		while (new[i])
		{
			free(new[i]);
			i++;
		}
		free(new);
		free(*line);
	}
	return (i);
}

int	get_xnum(char *file)
{
	char	**line;
	int		fd;
	int		i;

	i = 0;
	line = malloc(sizeof(char *));
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("error");
		exit(0);
	}
	else
	{
		i = read_x(fd, line);
		close(fd);
	}
	free(line);
	return (i);
}

int	get_ynum(char *file)
{
	char	**line;
	int		fd;
	int		i;

	i = 0;
	line = malloc(sizeof(char *));
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("error");
		exit(0);
	}
	else
	{
		while (get_next_line(fd, line))
		{
			free(*line);
			i++;
		}
		close(fd);
	}
	free(line);
	return (i);
}
