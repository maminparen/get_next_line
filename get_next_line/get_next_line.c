/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:33:08 by hzona             #+#    #+#             */
/*   Updated: 2021/11/08 16:40:17 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ret_line(ssize_t read_b, char *line)
{
	if (!read_b && line[read_b] == '\0')
	{
		free(line);
		return (0);
	}
	return (line);
}

static char	*read_line(char *line, char **rem, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	read_b;
	char	*tmp;

	read_b = 1;
	while (read_b)
	{
		read_b = read(fd, buffer, BUFFER_SIZE);
		if (read_b < 0)
		{
			free(line);
			return (0);
		}
		buffer[read_b] = '\0';
		line = ft_strjoin(line, buffer);
		if (ft_strchr(line, '\n'))
		{
			*rem = ft_strdup(ft_strchr(line, '\n') + 1);
			tmp = line;
			line = ft_substr(line, 0, ft_strlen(line) - ft_strlen(*rem));
			free(tmp);
			return (ret_line(read_b, line));
		}
	}
	return (ret_line(read_b, line));
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rem;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (0);
	if (!rem)
		rem = ft_strdup("");
	line = ft_strdup(rem);
	free(rem);
	rem = NULL;
	line = read_line(line, &rem, fd);
	return (line);
}
