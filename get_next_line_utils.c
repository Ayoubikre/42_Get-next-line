/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:26:18 by Noctis            #+#    #+#             */
/*   Updated: 2024/11/19 21:49:39 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	n1;
	size_t	n2;
	char	*dst;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	n1 = ft_strlen(s1);
	n2 = ft_strlen(s2);
	dst = malloc((n1 + n2 + 1) * 1);
	if (!dst)
		return (NULL);
	if (ft_strlcpy(dst, s1, (n1 + n2 + 1)) == n1)
		if (ft_strlcat(dst, s2, (n1 + n2 + 1)) == n1 + n2)
			return (dst);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	s1;

	if (!dst || !src)
		return (0);
	i = 0;
	s1 = ft_strlen(src);
	if (dstsize == 0)
		return (s1);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (s1);
}
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	s1;
	size_t	s2;

	if (!dst || !src)
		return (0);
	s1 = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (s1);
	s2 = ft_strlen(dst);
	if (dstsize <= s2)
		return (dstsize + s1);
	i = 0;
	while (src[i] && s2 + i < dstsize - 1)
	{
		dst[s2 + i] = src[i];
		i++;
	}
	dst[s2 + i] = '\0';
	return (s1 + s2);
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
