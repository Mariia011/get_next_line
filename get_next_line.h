/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:34:10 by marikhac          #+#    #+#             */
/*   Updated: 2024/02/23 17:33:11 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s, char const c);
char	*get_next_line(int fd);
char	*ft_memchar(char *str, char c);
char	*ft_strdup(char const *const memory);
void	ft_append(char **memory, char *buffer);
void	ft_free_old(char **memory);
void	read_line(int fd, char **memory);
#endif
