/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:54:46 by aelbouss          #+#    #+#             */
/*   Updated: 2025/04/21 18:45:24 by aelbouss         ###   ########.fr       */
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
	line[i] = 0 ;
	return (line);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

char	*get_line(int fd, char **buffer)
{
	char	*sub_buff;
	int		rb;

	if (!*buffer)
		*buffer = initialize_buffer(*buffer);
	if (!buffer)
		return (NULL);
	sub_buff = NULL;
	rb = 0;
	while (1)
	{
		if (ft_check(*buffer) != 1)
		{
			*buffer = read_to_buffer(*buffer, sub_buff, fd, rb);
			if (!*buffer)
				return (NULL);
		}
		else
			break ;
	}
	return (load_line(*buffer));
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd == -365)
	{
		free(buffer);
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = get_line(fd, &buffer);
	if (!line)
		return (NULL);
	buffer = update_buffer(buffer);
	if (!buffer)
		return (NULL);
	printf("buffer = (%s)\n",buffer);
	return (line);
}
