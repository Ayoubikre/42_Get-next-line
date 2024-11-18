/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:26:24 by Noctis            #+#    #+#             */
/*   Updated: 2024/11/18 18:56:38 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_check(char *t, unsigned int *i)
{
	if (!t)
		return (0);
	while (t[*i])
	{
		if (t[*i] == '\n')
		{
			(*i)++;
			return (1);
		}
		(*i)++;
	}
	return (0);
}
static char	*ft_fix(char *t, int i)
{
	int		j;
	char	*t2;

	j = 0;
	t2 = malloc(ft_strlen(t + i) + 1);
	while (t[i])
	{
		t2[j] = t[i];
		j++;
		i++;
	}
	free(t);
	t = ft_strdup(t2);
	free(t2);
	return (t);
}
static char	*ft_create(int fd, char *t)
{
	unsigned int	i;
	char			*line;
	char			*tmp;

	line = ft_strdup("");
	while (read(fd, t, BUFFER_SIZE) > 0)
	{
		i = 0;
		t[BUFFER_SIZE] = '\0';
		tmp = line;
		line = ft_strjoin(tmp, t);
		free(tmp);
		if (!line)
		{
			free(line);
			free(t);
			t = NULL;
			return (NULL);
		}
		if (ft_check(t, &i) == 1)
			break ;
	}
	t = ft_fix(t, i);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	i++;
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*t;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	t = malloc(BUFFER_SIZE + 1);
	if (!t)
	{
		free(t);
		t = NULL;
		return (NULL);
	}
	line = ft_create(fd, t);
	return (line);
}

// int	main(void)
// {
// 	int	fd;
// 	int	i;

// 	fd = open("./t.txt", O_RDWR);
// 	i = 0;
// 	while (i < 9)
// 	{
// 		printf("%s", get_next_line(fd));
// 		i++;
// 	}
// 	close(fd);
// }
