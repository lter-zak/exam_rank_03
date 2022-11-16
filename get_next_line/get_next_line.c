/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:04:12 by lter-zak          #+#    #+#             */
/*   Updated: 2022/11/16 17:03:58 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *main = malloc(10000);
	char *copy = main;

	if (BUFFER_SIZE == 1)
	{
		while (read(fd, copy, BUFFER_SIZE) > 0 && *copy++ != '\n')
		   ;	
	}
	else 
		while(read(fd, copy, 1) > 0 && *copy++ != '\n')
			;
	if (copy > main)
	{
		copy = 0;
		return (main);
	}
	free(main);
	return (0);
}
int main()
{
	int	fd;
	fd = open("txt.txt", O_RDONLY);
	printf("gnl = %s\n", get_next_line(fd));
}
