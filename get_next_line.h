/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 01:15:16 by kdahl             #+#    #+#             */
/*   Updated: 2020/06/28 01:16:48 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define LIMITS	1311

int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_strchr(const char *s, int ch);
char		*ft_strjoin(char *s1, char *s2);

#endif
