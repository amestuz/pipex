/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:22:40 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/11/06 18:48:02 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr_gnl(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char)c)
	{
		if (!*s)
			return (0);
		s++;
	}
	return ((char *)s);
}

char	*read_store(int fd, char *storage)
{
	int		rd;
	char	*buf;

	if (fd < 0)
		return (NULL);
	rd = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ft_free(&storage));
	buf[0] = '\0';
	while (rd > 0 && !ft_strchr_gnl(buf, '\n'))
	{
		rd = read (fd, buf, BUFFER_SIZE);
		if (rd > 0)
		{
			buf[rd] = '\0';
			storage = ft_strjoin_gnl(storage, buf);
		}
	}
	free(buf);
	if (rd == -1)
		return (ft_free(&storage));
	return (storage);
}

char	*rest_storage(char *storage)
{
	char	*buf2;
	int		len;

	if (!ft_strchr_gnl(storage, '\n'))
	{
		buf2 = NULL;
		return (ft_free(&storage));
	}
	else
		len = (ft_strchr_gnl(storage, '\n') - storage) + 1;
	if (!storage[len])
		return (ft_free(&storage));
	buf2 = ft_substr_gnl(storage, len, ft_strlen_gnl(storage) - len);
	ft_free(&storage);
	if (!buf2)
		return (NULL);
	return (buf2);
}

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*storage[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if ((storage[fd] && !ft_strchr_gnl(storage[fd], '\n')) || !storage[fd])
		storage[fd] = read_store(fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = ft_substr_gnl(storage[fd], 0, \
			(ft_strchr_gnl(storage[fd], '\n') - storage[fd] + 1));
	if (!line)
		return (ft_free(&storage[fd]));
	storage[fd] = rest_storage(storage[fd]);
	return (line);
}
/*int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line;
	int		i;

	line = NULL;
	fd = open("testo_prueba.txt", O_RDONLY);
	fd = open("testo_prueba2.txt", O_RDONLY);
	i = 0;

	while (i++ < 20)
	{
		line = get_next_line(fd1);
		printf("Line %d\n%s", i, line);
		free (line);
		line = get_next_line(fd2);
		printf("Line %d\n%s", i, line);
		free (line);
	}
	return (0);
}*/
