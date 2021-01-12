/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 18:26:50 by kdahl             #+#    #+#             */
/*   Updated: 2020/06/28 01:14:14 by kdahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		index;

	if (!(dest = (char *)malloc(sizeof(*dest) * (ft_strlen(s1) + 1))))
		return (NULL);
	index = 0;
	while (s1[index])
	{
		dest[index] = s1[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int ch)
{
	int	index;

	index = 0;
	while (s[index])
	{
		if (s[index] == ch)
			return ((char *)&s[index]);
		index++;
	}
	if (s[index] == '\0' && (char)ch == '\0')
		return ((char *)&s[index]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		index1;
	int		index2;

	if (!s1 && !s2)
		return (NULL);
	if (!(s1) || !(s2))
		return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
	if (!(str = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	index1 = 0;
	index2 = 0;
	while (s1[index1])
		str[index1++] = s1[index2++];
	index2 = 0;
	while (s2[index2])
		str[index1++] = s2[index2++];
	str[index1] = '\0';
	return (str);
}
