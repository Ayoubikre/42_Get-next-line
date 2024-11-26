/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:30:31 by aakritah          #+#    #+#             */
/*   Updated: 2024/11/26 21:05:14 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fix_str(char *str, int i)
{
	char	*t;

	t = ft_strdup(str + i);
	if (!t)
		return (free(str), str = NULL, NULL);
	return (t);
}

char	*ft_get_line(char *str, int *i)
{
	char	*t;
	int		j;

	while (str[*i] || str[*i] != '\n')
		(*i)++;
	if (str[*i] == '\n')
		(*i)++;
	t = malloc(*i + 1);
	if (!t)
		return (NULL);
	j = 0;
	while (j <= *i)
	{
		t[j] = str[j];
		j++;
	}
	t[j] = '\0';
	return (t);
}

char	*ft_get_str(int fd, char *str)
{
	char	buff[BUFFER_SIZE];
	int		rs;

	// char	*buff;
	rs = 1;
	// buff=malloc(BUFFER_SIZE+1);
	if (!str)
		str = ft_strdup("");
	while (rs > 0)
	{
		rs = read(fd, buff, BUFFER_SIZE);
		if (rs < 1 && (!str || !str[0]))
			return (free(str), str = NULL, NULL);
		buff[rs] = '\0';
		str = ft_strjoin(str, buff);
		if (!str)
			return (NULL);
		if (ft_strchr(str, '\n') != NULL)
			break ;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) == -1)
		return (free(str), str = NULL, NULL);
	str = ft_get_str(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str, &i);
	if (!line)
		return (free(str), str = NULL, NULL);
	str = ft_fix_str(str, i);
	return (str);
}
