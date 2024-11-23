/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:26:18 by Noctis            #+#    #+#             */
/*   Updated: 2024/11/20 17:17:17 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		size_total;
	char	*res;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s1)
		return (ft_strdup(s2));
	size_total = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(size_total + 1);
	if (!res)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s1;
	char	*dst;

	if (!s)
		return (NULL);
	i = 0;
	if ((unsigned int)ft_strlen(s) <= start)
		return (ft_strdup(""));
	s1 = ft_strlen(s + start);
	if (len < s1)
		s1 = len;
	dst = malloc((s1 + 1) * 1);
	if (!dst)
		return (NULL);
	while (i < s1)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	s;
	char	*t;

	if (!s1)
		return (NULL);
	s = ft_strlen(s1);
	t = malloc((s + 1) * 1);
	if (!t)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		t[i] = s1[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	s1;
	size_t	i;

	s1 = ft_strlen(s);
	i = 0;
	while (i < s1 + 1)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

