/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:26:24 by Noctis            #+#    #+#             */
/*   Updated: 2024/11/19 19:14:18 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check(char *t)
{
	int	i;

	i = 0;
	while (t[i])
	{
		if (t[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_get_buffer(int fd, char *buffer)
{
	char	*t;

	t = malloc(BUFFER_SIZE + 1);
	if (!t)
		return (NULL);
	while (ft_check(buffer) == 0 && read(fd, t, BUFFER_SIZE) > 0)
	{
		buffer = ft_strjoin(buffer, t);
		if (!buffer)
			break ;
		if (ft_check(t) == 1)
			break ;
	}
	free(t);
	t = NULL;
	return (buffer);
}

char	*ft_get_line(char *buffer)
{
	int		i;
	char	*t;

	i = 0;
	if (!buffer)
		return (NULL);
	t = malloc(ft_strlen(buffer) + 1);
	if (!t)
		return (NULL);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			t[i] = buffer[i];
			i++;
			break ;
		}
		t[i] = buffer[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}

char	*ft_fix(char *buffer)
{
	int		i;
	char	*t;

	i = 0;
	t = ft_strdup(buffer);
	while (t[i])
	{
		if (t[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	free(buffer);
	buffer = ft_substr(t, i, ft_strlen(t));
	free(t);
	t = NULL;
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (!buffer)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		buffer[BUFFER_SIZE] = '\0';
	}
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_get_buffer(fd, buffer);
	line = ft_get_line(buffer);
	// if (!line)
	// {
	// 	free(buffer);
	// 	buffer = NULL;
	// 	return (NULL);
	// }
	buffer = ft_fix(buffer);
	// printf("\n----------------\n");
	// printf("1:| %s  |\n", buffer);
	// printf("2:| %s  |\n", line);
	// printf("----------------\n");
	return (line);
}
