/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:11:04 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/05/17 19:59:17 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	dest_len;
	unsigned int	i;

	dest_len = 0;
	i = 0;
	while (dst[dest_len] && dest_len < dstsize)
		dest_len++;
	if (dest_len == dstsize)
	{
		return (dest_len + ft_strlen(src));
	}
	while (src[i] && (dest_len + i < dstsize - 1))
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (dest_len + ft_strlen(src));
}

/*
int	main()
{
	 char *dst = NULL;
	char s1[] = "Hello";
    char s2[] = "Word";
   // printf("%zu", ft_strlcat(s1, s2, 6));
	printf("%zu\n", ft_strlcat(s1, s2, 11));
	printf("%s\n", s1);
	printf("%s\n", dst);
    return (0);
}
*/