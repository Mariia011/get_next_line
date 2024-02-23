/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:40:45 by marikhac          #+#    #+#             */
/*   Updated: 2024/02/23 20:03:05 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_line(int fd, char **memory)
{
	char		buf[BUFFER_SIZE + 1];
	int char_read;

	buf[BUFFER_SIZE] = '\0';
	while (!ft_memchar(*memory, '\n'))
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read)
			break ;
		buf[char_read] = '\0';
		ft_append(memory, buf);
	}
}

void *ft_free_mem(char **chlp)
{
		free(*chlp);
		*chlp = NULL;
		return NULL;
}

char	*get_next_line(int fd)
{
	static char	*memory;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!memory)
	{
		memory = malloc(1);
		memory[0] = '\0';
	}
	else
	{
		if (ft_memchar(memory, '\n'))
			ft_free_old(&memory);
		else
			return(ft_free_mem(&memory));
	}
	read_line(fd, &memory);
	if (*memory == '\0')
		return(ft_free_mem(&memory));
	return (ft_strdup(memory));
}

// #include <string.h>

// char	*str;
// int count = 1;

// void gnl(int fd, char *mtr)
// {
// 	printf("Test %d : ", count++);
// 	str = get_next_line(fd);

// 	if (!str && !mtr)
// 	{
// 		printf("NULK\n");
// 		return;
// 	}

// 	printf("%d\n", strcmp(str, mtr));
// 	//printf("%s", str);
// }

// int	main(void)
// {
// 	int		fd;
// 	fd = open("/Users/marikhac/Desktop/get_next_line/tester/files/multiple_line_with_nl", O_RDONLY);
// 	/* 1 */ gnl(fd, "9876543210987654321098765432109876543210\n");
// 		 /* 2 */ gnl(fd, "01234567890123456789012345678901234567890\n");
// 		 /* 3 */ gnl(fd, "987654321098765432109876543210987654321098\n");
// 		 /* 4 */ gnl(fd, "01234567890123456789012345678901234567890\n");
// 		 /* 5 */ gnl(fd, "9876543210987654321098765432109876543210\n");
// 		 /* 6 */ gnl(fd, NULL);


// 	close(fd);
// 	free(str);
// }
