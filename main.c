/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:53:15 by aakritah          #+#    #+#             */
/*   Updated: 2024/11/19 21:50:40 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int fd;
	int i;
	char *k;

	fd = open("./a.txt", O_RDWR);
	i = 0;
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	while (1)
	{
		k = get_next_line(fd);
		if (!k || k[0] == '\0')
			break ;
		printf("%s", k);
		printf("\n----------------\n");
	}
	//--------------------------------------------
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// while (i < 9)
	// {
	// 	printf("%s", get_next_line(fd));
	// 	// k = get_next_line(fd);
	// 	// printf("%s", k);
	// 	// free(k);
	// 	i++;
	// }
	close(fd);

	// printf("hello");
	// printf("%s", k);
}