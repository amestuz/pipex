/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:18:32 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/05/01 19:45:42 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdlib.h>
#include <stdio.h>*/

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dest;

	len = ft_strlen(s1);
	dest = malloc(len * sizeof(char) + 1);
	if (dest == NULL)
		return (0);
	ft_memcpy(dest, s1, len);
	dest[len] = '\0';
	return (dest);
}

/*
int	main(void)
{
	char	*s1;

	s1 = "";
	printf("Hola 1\n");
	printf("tu funcion: %s\n", ft_strdup(s1));
	printf("Hola 2\n");
	printf("la original: %s\n", strdup(s1));
}
*/