/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 01:05:53 by kdahl             #+#    #+#             */
/*   Updated: 2020/06/28 02:43:05 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	create_newline(char **str, char **line, char *n_line)
{
	char	*remember;

	*line = ft_strdup(*str);
	if (*line == NULL)
		return (-1);
	if (*n_line == '\0')
	{
		free(*str);
		*str = NULL;
		return (1);
	}
	remember = ft_strdup(n_line);
	if (remember == NULL)
		return (-1);
	free(*str);
	*str = remember;
	return (1);
}

static int	read_last(char **str, char **line, int read_process)
{
	char	*n_line;

	if (read_process < 0)
		return (-1);
	if ((*str) && (n_line = ft_strchr(*str, '\n')))
	{
		*n_line++ = '\0';
		return (create_newline(str, line, n_line));
	}
	if (*str)
	{
		*line = *str;
		*str = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*str[LIMITS];
	char		buf[BUFFER_SIZE + 1];
	char		*n_line;
	int			read_process;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0 || (read(fd, buf, 0) < 0))
		return (-1);
	while ((read_process = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_process] = '\0';
		n_line = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = n_line;
		if ((n_line = ft_strchr(str[fd], '\n')))
		{
			*n_line++ = '\0';
			return (create_newline(&str[fd], line, n_line));
		}
	}
	return (read_last(&str[fd], line, read_process));
}
