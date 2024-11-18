/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:26:24 by Noctis            #+#    #+#             */
/*   Updated: 2024/11/18 01:32:40 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	del(void *data)
{
	free(data);
}

static char	*ft_copy(t_list *lst)
{
	int		i;
	int		j;
	char	*t;
	t_list	*ptr;

	i = 0;
	j = 0;
	ptr = lst;
	while (ptr)
	{
		j = 0;
		while (((char *)ptr->content)[j] && ((char *)ptr->content)[j] != '\n')
		{
			j++;
			i++;
		}
		ptr = ptr->next;
	}
	// printf("\n i = | %d |\n",i);
	t = malloc(i + 1);
	if (!t)
		return (NULL);
	i = 0;
	while (lst)
	{
		j = 0;
		while (((char *)lst->content)[j] && ((char *)lst->content)[j] != '\n')
		{
			t[i] = ((char *)lst->content)[j];
			j++;
			i++;
		}
		lst = lst->next;
	}
	t[i] = '\0';
	// printf("\n t = | %s |\n",t);
	return (t);
}

static void	ft_fix(t_list **lst)
{
	char	*t;
	char	*t2;
	t_list	*ptr;

	ptr = ft_lstlast(*lst);
	if (!ptr || !ptr->content)
		return ;
	t2 = ft_strchr((char *)ptr->content, '\n');
	if (!t2)
		return ;
	t2++;
	t = ft_strdup(t2);
	ft_lstclear(lst, del);
	ft_lstadd_back(lst, ft_lstnew(t));
}

static char	*ft_get_line(int fd, t_list **lst)
{
	char	*t;
	char	*t2;

	t2 = malloc(BUFFER_SIZE + 1);
	if (!t2)
		return (NULL);
	while (read(fd, t2, BUFFER_SIZE) > 0)
	{
		t2[BUFFER_SIZE] = '\0';
		if (ft_strchr(t2, '\n') != NULL)
		{
			ft_lstadd_back(lst, ft_lstnew(ft_strdup(t2)));
			free(t2);
			break ;
		}
		ft_lstadd_back(lst, ft_lstnew(ft_strdup(t2)));
	}
	free(t2);
	if (!*lst)
		return (NULL);
	t = ft_copy(*lst);
	ft_fix(lst);
	return (t);
}

// static void	ft_fix(t_list **lst)
// {
// 	t_list	*ptr;
// 	char	*t2;

// 	ptr = ft_lstlast(*lst);
// 	if (!ptr || !ptr->content)
// 		return ;
// 	t2 = ft_strchr((char *)ptr->content, '\n');
// 	if (!t2)
// 		return ;
// 	t2++;                                      // Skip '\n'
// 	char *remaining = ft_strdup(t2);
// 		// Allocate memory for remaining content
// 	ft_lstclear(lst, del);                     // Clear old list
// 	ft_lstadd_back(lst, ft_lstnew(remaining));
// 		// Add remaining content as new node
// }

// static char	*ft_get_line(int fd, t_list **lst)
// {
// 	char	*buffer;
// 	char	*line;

// 	buffer = malloc(BUFFER_SIZE + 1);
// 	if (!buffer)
// 		return (NULL);
// 	while (read(fd, buffer, BUFFER_SIZE) > 0)
// 	{
// 		buffer[BUFFER_SIZE] = '\0';
// 		ft_lstadd_back(lst, ft_lstnew(ft_strdup(buffer)));
// 		if (ft_strchr(buffer, '\n'))
// 			break ;
// 	}
// 	free(buffer);
// 	if (!*lst)
// 		return (NULL);
// 	line = ft_copy(*lst);
// 	ft_fix(lst);
// 	return (line);
// }

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*t;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	t = ft_get_line(fd, &lst);
	return (t);
}

// int	main(void)
// {
// 	int fd = open("./t.txt", O_RDWR);
// 	int i = 0;
// 	while (i < 3)
// 	{
// 		printf("\n%s", get_next_line(fd));
// 		i++;
// 	}
// 	close(fd);
// }