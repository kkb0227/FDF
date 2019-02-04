/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 16:31:30 by kykim             #+#    #+#             */
/*   Updated: 2018/06/14 14:26:29 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		savethebuff(char *data[1024], char **line, int fd)
{
	int		i;
	char	*tmp;

	i = 0;
	while (data[fd][i] != '\n' && data[fd][i] != '\0')
		i++;
	if (data[fd][i] == '\n')
	{
		*line = ft_strsub(data[fd], 0, i);
		tmp = ft_strdup(data[fd] + i + 1);
		ft_strdel(&data[fd]);
		if (*tmp)
			data[fd] = ft_strdup(tmp);
		ft_strdel(&tmp);
		return (1);
	}
	else
	{
		*line = ft_strdup(data[fd]);
		ft_strdel(&data[fd]);
		return (1);
	}
}

char	*joinandsave(char *str, char *buff)
{
	char *temp;

	temp = ft_strjoin(str, buff);
	ft_strdel(&str);
	str = ft_strdup(temp);
	ft_strdel(&temp);
	return (str);
}

char	*initialize(char **data, int fd)
{
	if (data[fd] == NULL)
		data[fd] = ft_strnew(0);
	return (data[fd]);
}

int		get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	int			readsize;
	static char	*data[1024];

	if (!line || fd < 0)
		return (-1);
	*line = NULL;
	while ((readsize = read(fd, buff, BUFF_SIZE)) > 0)
	{
		data[fd] = initialize(data, fd);
		buff[readsize] = '\0';
		data[fd] = joinandsave(data[fd], buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (readsize < 0)
		return (-1);
	else if (readsize == 0 && data[fd] == NULL)
	{
		if (*line)
			ft_strdel(line);
		return (0);
	}
	else
		return (savethebuff(data, line, fd));
}
