/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:50:44 by aelbouss          #+#    #+#             */
/*   Updated: 2025/04/21 18:03:33 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//headers section
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//prototypes  section
char	*get_next_line(int fd);
char	*get_line(int fd, char **buffer);
char	*initialize_buffer(char *b);
char	*ft_strdup(char *src);
char	*read_to_buffer(char *buffer, char *sub_buf, int fd, int rb);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_cnt(char *s);
size_t	ft_strlen(const char *s);
int	ft_check(char *s);
#endif
