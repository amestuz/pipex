/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:05:54 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/04/27 20:33:07 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s)
			return (0);
		s++;
	}
	return ((char *)s);
}

/* char	*ft_strchr(const char *s, int c)
{
	while (s)
	{
		if (*s == (char)c)
			return ((char *)s);
		else if (*s == '\0')
			return (0);
		s++;
	}
	return (0);
} */

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	//char	*s = "\0";
	printf("%s\n", ft_strchr(((void *)0), '\0'));
	printf("%s\n", strchr(((void *)0), '\0'));
} */
