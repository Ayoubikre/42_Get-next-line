/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:26:24 by Noctis            #+#    #+#             */
/*   Updated: 2024/11/20 17:17:34 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fix_left(char *line, char *left)
{
	char	*tmp;
	int		i;
	int		j;

	if (left)
	{
		free(left);
		left = NULL;
	}
	tmp = ft_strchr(line, '\n');
	if (!tmp)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	left = malloc(i + 1);
	if (!left)
		return (NULL);
	j = 0;
	while (j < i)
	{
		left[j] = line[j];
		j++;
	}
	return (left);
}

char	*ft_fix_line(char *line, char *left)
{
	int		i=0;
	int		s1;
	char	*t;
	char	*t2;

	while()
	
}


char	*get_next_line(int fd)
{
	static char *left;
	char *line;
	char buffer[BUFFER_SIZE];

	line = calloc(1, 1);
	if (left)
	{
		line = ft_strjoin(left, buffer);
		if (!line)
			return (free(line), line = NULL, free(left), left = NULL, NULL);
	}
	buffer[BUFFER_SIZE] = '\0';
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buffer);
		if (!line)
			return (free(line), line = NULL, free(left), left = NULL, NULL);
		if (ft_strchr(line, '\n'))
			break ;
	}
	line = ft_fix_line(line, left);
	if (!line)
		return (free(line), line = NULL, free(left), left = NULL, NULL);
	left = ft_fix_left(line, left);
	if (!left)
		return (free(line), line = NULL, free(left), left = NULL, NULL);
	return (line);
}
