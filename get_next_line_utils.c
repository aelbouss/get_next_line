/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:51:55 by aelbouss          #+#    #+#             */
/*   Updated: 2025/04/21 18:00:54 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_cnt(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

char	*initialize_buffer(char *b)
{
	b = ft_strdup("");
	if (!b)
		return (NULL);
	b[0] = '\0';
	return (b);
}

char	*read_to_buffer(char *buffer, char *sub_buff, int fd, int rb)
{
	char	*holder;

	sub_buff = malloc(((BUFFER_SIZE * sizeof(char)) + 1));
	if (!sub_buff)
		return (NULL);
	sub_buff[BUFFER_SIZE] = '\0';
	rb = read(fd, sub_buff, BUFFER_SIZE);
	if (rb <= 0)
	{
		free(sub_buff);
		sub_buff = NULL;
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	holder = buffer;
	buffer = ft_strjoin(buffer, sub_buff);
	if (!buffer)
		return (NULL);
	free(sub_buff);
	free(holder);
	sub_buff = NULL;
	return (buffer);
}

int	ft_check(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
