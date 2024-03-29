/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:45:21 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/06/09 20:57:52 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*strj;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	strj = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!strj)
		return (ft_free(&s1));
	i = -1;
	while (s1[++i])
		strj[i] = s1[i];
	j = -1;
	while (s2[++j])
		strj[ft_strlen(s1) + j] = s2[j];
	strj[ft_strlen(s1) + j] = '\0';
	return (free(s1), strj);
}

char	*ft_strdup(char *s1)
{
	size_t			len;
	char			*dest;

	if (!s1)
		return (ft_strdup(""));
	len = ft_strlen(s1);
	dest = malloc(len * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	while (len--)
		dest[len] = s1[len];
	dest[len] = '\0';
	return (dest);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	unsigned int	i;

	if (size == 0)
	{
		return (ft_strlen(src));
	}
	i = 0;
	while (i < (size - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	dlen;
	char	*dest;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	dlen = 0;
	if (start >= slen)
		return (ft_strdup(""));
	if (slen > start)
	{
		dlen = slen - start;
		if ((slen - start) > len)
			dlen = len;
	}
	dest = malloc(sizeof(char) * (dlen + 1));
	if (!dest)
		return (0);
	ft_strlcpy(dest, &s[start], dlen + 1);
	return (dest);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
