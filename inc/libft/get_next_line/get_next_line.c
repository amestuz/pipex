/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:22:40 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/06/11 19:53:25 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
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
	while (rd > 0 && !ft_strchr(buf, '\n'))
	{
		rd = read (fd, buf, BUFFER_SIZE);
		if (rd > 0)
		{
			buf[rd] = '\0';
			storage = ft_strjoin(storage, buf);
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

	if (!ft_strchr(storage, '\n'))
	{
		buf2 = NULL;
		return (ft_free(&storage));
	}
	else
		len = (ft_strchr(storage, '\n') - storage) + 1;
	if (!storage[len])
		return (ft_free(&storage));
	buf2 = ft_substr(storage, len, ft_strlen(storage) - len);
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
	static char		*storage = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if ((storage && !ft_strchr(storage, '\n')) || !storage)
		storage = read_store(fd, storage);
	if (!storage)
		return (NULL);
	line = ft_substr(storage, 0, (ft_strchr(storage, '\n') - storage + 1));
	if (!line)
		return (ft_free(&storage));
	storage = rest_storage(storage);
	return (line);
}
/*int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	line = NULL;
	fd = open("testo_prueba.txt", O_RDONLY);
	i = 0;

	while (i++ < 20)
	{
		line = get_next_line(fd);
		printf("Line %d\n%s", i, line);
		free (line);
	}
	return (0);
}*/
