/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:26:24 by Noctis            #+#    #+#             */
/*   Updated: 2024/11/23 13:40:48 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *str)
{
	char	*t;
	int		i;
	int		j;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	t = malloc(++i + 1);
	if (!t)
		return (free(str), str = NULL, NULL);
	j = 0;
	while (j < i)
	{
		t[j] = str[j];
		j++;
	}
	t[j] = '\0';
	return (t);
}

char	*ft_fix_str(char *str)
{
	char	*t;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (free(str),str=NULL,NULL);
	i++;
	while (str[i + j])
		j++;
	t = malloc(j + 1);
	if (!t)
		return (free(str), str = NULL, NULL);
	j = 0;
	while (str[i + j])
	{
		t[j] = str[i + j];
		j++;
	}
	t[j] = '\0';
	free(str);
	return (t);
}

char	*ft_get_str(int fd, char *str)
{
	char	*buffer;
	char	*t;
	ssize_t	rs;

	rs = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(str), str = NULL, str);
	while (rs != 0 && !ft_strchr(str, '\n'))
	{
		rs = read(fd, buffer, BUFFER_SIZE);
		if (rs == -1)
			return (free(buffer), buffer = NULL, free(str), str = NULL, str);
		if (rs == 0 && (!str || str[0] == '\0'))
			return (free(buffer), free(str), NULL);
		buffer[rs] = '\0';
		t = str;
		str = ft_strjoin(str, buffer);
		free(t);
	}
	return (free(buffer), buffer = NULL, str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (free(str), str = NULL, NULL);
	str = ft_get_str(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	if (!line)
		return (free(str), str = NULL, NULL);
	str = ft_fix_str(str);
	return (line);
}
