/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:43:07 by fimazouz          #+#    #+#             */
/*   Updated: 2024/05/06 19:31:50 by fimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_struct
{
	char	*buffer;
	int		readbytes;
	char	*line;
	char	*new_tmp;
}			t_struct;

char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlenline(const char *str, char c, int num);
size_t		ft_strlen(const char *str);
char		*get_next_line(int fd);
char		*ft_buff(t_struct data, char **saved);
char		*last(t_struct data, int fd, char **saved);
char		*ft_strcpy(char *src, char c);

#endif