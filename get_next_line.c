/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Noctis <Noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:26:24 by Noctis            #+#    #+#             */
/*   Updated: 2024/11/18 00:17:01 by Noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void del(void *data)
{
	free(data);
}

char	*get_next_line(int fd)
{
	int				i;
	int				j;
	int				k;
	static t_list	*lst;
	t_list			*ptr;
	char			*t;
	char			*t2;
	char			*t3;

	ptr = NULL;
	if (fd < 0 || write(1, NULL, 0) != 0)
		return (NULL);
	t = malloc(BUFFER_SIZE + 1);
	while (read(fd, t, BUFFER_SIZE) > 0)
	{
		t[BUFFER_SIZE] = '\0';
		ft_lstadd_back(&lst, ft_lstnew(ft_strdup(t)));
		if (ft_strchr(t, '\n'))
			break ;
	}
	ptr = lst;
	i = 0;
	while (ptr)
	{
		j = 0;
		t2 = ptr->content;
		while (t2[j] && t2[j] != '\n')
		{
			j++;
			i++;
		}
		ptr = ptr->next;
	}
	t3 = malloc(i + 1);
	ptr = lst;
	i = 0;
	while (ptr)
	{
		j = 0;
		t2 = ptr->content;
		while (t2[j] && t2[j] != '\n')
		{
			t3[i] = t2[j];
			j++;
			i++;
		}
		ptr = ptr->next;
	}
	ptr=ft_lstlast(lst);
	t2 = ptr->content;
	t2=ft_strchr(t2,'\n');
	t2=ft_strdup(t2);
	ft_lstclear(&lst,del);
	ft_lstadd_back(&lst,ft_lstnew(t2));
	
	return (t3);
}

int	main(void)
{
	int fd = open("./t.txt", O_RDWR);
	int i = 0;
	while (i < 7)
	{
		printf("\n%s", get_next_line(fd));
		i++;
	}
	close(fd);
}