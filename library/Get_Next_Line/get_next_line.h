/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 16:31:43 by kykim             #+#    #+#             */
/*   Updated: 2018/06/13 20:06:09 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# define BUFF_SIZE 50

int		savethebuff(char *data[1024], char **line, int fd);
char	*joinandsave(char *str, char *buff);
int		get_next_line(const int fd, char **line);
char	*initialize(char **data, int fd);

#endif
