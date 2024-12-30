/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:11:27 by fimazouz          #+#    #+#             */
/*   Updated: 2024/05/07 10:51:22 by fimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlenline(const char *str, char c, int num)
{
	size_t	i;

	i = 0;
	if (num == 1)
	{
		while (str[i] != c)
			i++;
		i += 2;
		return (i);
	}
	else
	{
		while (str[i])
		{
			if (str[i] == c)
				return (1);
			i++;
		}
		return (0);
	}
}

char	*ft_strcpy(char *src, char c)
{
	int		i;
	char	*dst;
	size_t	len;

	i = 0;
	len = ft_strlenline(src, '\n', 1);
	dst = malloc(len * sizeof(char));
	if (!dst)
		return (NULL);
	while (src[i] != c)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\n';
	i++;
	dst[i] = '\0';
	return (dst);
}

char	*ft_buff(t_struct data, char **saved)
{
	data.buffer[data.readbytes] = '\0';
	data.new_tmp = ft_strjoin(*saved, data.buffer);
	free(*saved);
	*saved = data.new_tmp;
	return (*saved);
}

char	*last(t_struct data, int fd, char **saved)
{
	while (data.readbytes > 0 && !ft_strlenline(data.buffer, '\n', 0))
	{
		data.readbytes = read(fd, data.buffer, BUFFER_SIZE);
		if (data.readbytes == -1)
			return (free(data.buffer), free(*saved), *saved = NULL, NULL);
		*saved = ft_buff(data, &*saved);
		if (ft_strlenline(*saved, '\n', 0))
		{
			data.line = ft_strcpy(*saved, '\n');
			data.new_tmp = ft_strchr(*saved, '\n');
			free(*saved);
			*saved = data.new_tmp;
			break ;
		}
		if (data.readbytes == 0 && *saved[0] != '\0')
		{
			data.line = ft_strdup(*saved);
			free(*saved);
			*saved = NULL;
		}
		else if (data.readbytes == 0 && *saved[0] == '\0')
			return (free(*saved), free(data.buffer), *saved = NULL, NULL);
	}
	return (free(data.buffer), data.line);
}

char	*get_next_line(int fd)
{
	t_struct	data;
	static char	*saved;

	data.readbytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	data.buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!data.buffer)
		return (NULL);
	data.buffer[0] = '\0';
	if (!saved)
		saved = ft_strdup("");
	return (last(data, fd, &saved));
}

// #include <fcntl.h>
// #include <stdio.h>
// int	main(int ac, char **av)
// {
// 	int	fd;

// 	fd = open(av[ac - 1], O_RDONLY);
// 	char *s;
// 	int cont = 1;
// 	while (cont)
// 	{
// 		s = get_next_line(fd);
// 		printf("<%s>", s);
// 		cont = s != NULL;
// 		if (s)
// 			free(s);
// 	}
// 	//printf("%s", get_next_line(fd));

// 	//system("leaks a.out");
// }
