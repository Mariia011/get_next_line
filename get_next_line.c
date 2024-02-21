/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:40:45 by marikhac          #+#    #+#             */
/*   Updated: 2024/02/21 20:10:56 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char				buf[BUFFER_SIZE + 1];
	static char			*memory;
	int					char_read;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (NULL);

	if(!memory)
	{
		memory = malloc(1);
		memory[0] = '\0';
	}
	else
	{
		//printf("%s", memory);
		if(ft_memchar(memory, '\n'))
			ft_free_old(&memory);
		else
		{
			free(memory);
			memory = NULL;
			return(NULL);
		}
	}
	buf[BUFFER_SIZE] = '\0';
	while (!ft_memchar(memory, '\n'))
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read)
			break ;
		buf[char_read] = '\0';
		ft_append(&memory, buf);
	}
	return (ft_strdup(memory));
}

// int	main(void)
// {
// 	int		td;
// 	char	*str;

// 	td = open("file.txt", O_RDONLY);
// 	str = get_next_line(td);
// 	printf("%s", str);
// 	str = get_next_line(td);
// 	printf("%s", str);
// 	str = get_next_line(td);
// 	printf("%s", str);
// 	str = get_next_line(td);
// 	printf("%s", str);

// 	close(td);
// 	free(str);
// }
