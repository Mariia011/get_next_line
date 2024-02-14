/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:40:45 by marikhac          #+#    #+#             */
/*   Updated: 2024/02/14 21:09:43 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			fd;
	char		buf[BUFFER_SIZE + 1];
	static char	*line;
	int			char_read;

	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("esh\n");
		return (-1);
	}
	line = malloc(1);
	line[0] = '\0';
	buf[BUFFER_SIZE] = '\0';
	while (ft_strchr(line, "\n"))
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read)
			break ;
		buf[char_read] = '\0';
	}
	return (1);
}
