/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:34:10 by marikhac          #+#    #+#             */
/*   Updated: 2024/02/14 21:09:41 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*ft_memchar(char *str, char c);
void	ft_append(char **memory, char *buffer);

# endif
