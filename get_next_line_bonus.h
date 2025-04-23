/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:55:30 by aelbouss          #+#    #+#             */
/*   Updated: 2025/04/23 12:03:21 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
//headers section
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

//prototypes  section
char	*get_next_line(int fd);
char	*get_line(int fd, char **buffer);
char	*initialize_buffer(void);
char	*ft_strdup(char *src);
void	read_to_buffer(char **buffer, char *sub_buf, int fd, int *flag);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_cnt(char *s);
size_t	ft_strlen(const char *s);
int		ft_check(char *s);
void	*ft_calloc(size_t count, size_t size);

#endif 
