/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:15:08 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/06/22 20:17:08 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
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

/*int	main(void)
{
	printf("%s\n", ft_substr("hola", 0, 18446744073709551615));
	return (0);
}*/
