/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:34:03 by marikhac          #+#    #+#             */
/*   Updated: 2024/02/14 21:09:38 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void ft_append(char **memory, char *buffer)
{
	int i;
	int d;
	int t;
	char *tmp;

	tmp = malloc(ft_strlen(memory) + ft_strlen(buffer) + 1);
	i = 0;
	d = 0;
	t = 0;
	while((*memory)[i] || buffer[d])
	{
		if((*memory)[i])
			tmp[t] = (*memory)[i++];
		else
			tmp[t] = buffer[d++];
		t++;
	}
	tmp[t] = '\0';
	free(*memory);
	*memory = tmp;
}

char *ft_memchar(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (str) ;
		str++;
	}
	return (NULL);
}
