/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:26:24 by Noctis            #+#    #+#             */
/*   Updated: 2024/11/23 17:29:58 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fix_str(char *str, int i)
{
	char	*t;

	t = ft_strdup(str + i);
	if (!t)
		return (free(str), str = NULL, NULL);
	return (free(str), str = NULL, t);
}

char	*ft_get_line(char *str, int *i)
{
	char	*t;
	int		j;

	*i = 0;
	while (str[*i] && str[*i] != '\n')
		(*i)++;
	if (str[*i] == '\n')
		(*i)++;
	t = malloc(*i + 1);
	if (!t)
		return (NULL);
	j = 0;
	while (j < *i)
	{
		t[j] = str[j];
		j++;
	}
	t[j] = '\0';
	return (t);
}

char	*ft_get_str(int fd, char *str)
{
	char	*buffer;
	ssize_t	i;

	i = 1;
	if (!str)
		str = ft_strdup("");
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(str), str = NULL, NULL);
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 1 && (!str || !str[0]))
			return (free(buffer), buffer = NULL, free(str), str = NULL, NULL);
		buffer[i] = '\0';
		str = ft_strjoin(str, buffer);
		if (!str)
			return (NULL);
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (free(buffer), buffer = NULL, str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
		return (free(str), str = NULL, NULL);
	str = ft_get_str(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str, &i);
	if (!line)
		return (free(str), str = NULL, NULL);
	str = ft_fix_str(str, i);
	return (line);
}
