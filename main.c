/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:53:15 by aakritah          #+#    #+#             */
/*   Updated: 2024/11/23 16:18:05 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int	main(void)
{
	int fd= open("./a.txt", O_RDWR);

	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	char *k;
	while (1)
	{
		k = get_next_line(fd);
		if (!k || k[0] == '\0')
			break ;
		printf("%s", k);
	}
	printf("\n--------------------------------------------");
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
	// close(fd);

	// printf("hello");
	// printf("%s", k);
}