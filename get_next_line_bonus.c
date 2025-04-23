/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:54:46 by aelbouss          #+#    #+#             */
/*   Updated: 2025/04/23 12:03:06 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update_buffer(char *b)
{
	int			i;
	char		*tmp;

	i = 0;
	while (b[i] && b[i] != '\n')
		i++;
	if (b[i] == '\0')
	{
		free(b);
		return (NULL);
	}
	i++;
	tmp = ft_strdup(&b[i]);
	if (!tmp)
		return (NULL);
	free(b);
	b = NULL;
	return (tmp);
}

char	*load_line(char *s)
{
	size_t		i;
	char		*line;
	int			idx;

	if (!s)
		return (NULL);
	i = ft_cnt(s);
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	idx = 0;
	while (s[i])
	{
		line[idx++] = s[i++];
		if (line[idx - 1] == '\n')
			break ;
	}
	line[idx] = '\0';
	return (line);
}

char	*join_and_free(char *s1, char *s2)
{
	char	*b;

	if (!s1)
		s1 = initialize_buffer();
	if (!s1)
		return (NULL);
	b = ft_strjoin(s1, s2);
	if (!b)
		return (NULL);
	free(s1);
	free(s2);
	return (b);
}

char	*get_line(int fd, char **buffer)
{
	char	*sub_buff;
	int		rb;

	rb = 1;
	while (1)
	{
		if (ft_check(buffer[fd]) == 1)
			break ;
		sub_buff = malloc((BUFFER_SIZE * sizeof(char)) + 1);
		if (!sub_buff)
			return (NULL);
		rb = read(fd, sub_buff, BUFFER_SIZE);
		if (rb <= 0)
		{
			free(sub_buff);
			break ;
		}
		sub_buff[rb] = '\0';
		buffer[fd] = join_and_free(buffer[fd], sub_buff);
		if (!buffer[fd])
			return (NULL);
	}
	if (ft_strlen(buffer[fd]) == 0)
		return (NULL);
	return (load_line(buffer[fd]));
}

char	*get_next_line(int fd)
{
	static char	*buffer[1090];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = get_line(fd, buffer);
	if (!line)
		return (NULL);
	buffer[fd] = update_buffer(buffer[fd]);
	return (line);
}
