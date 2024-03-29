/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:05:54 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/04/28 22:03:20 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = (int)ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (0);
}

/*	
	sszite	i;
	parece que con este tipo me permite el valor -1 y tb funcionaria
*/
/*	o poner esto en vez del strlen con i que es un int
	i = 0;
	while (s[i])
		i++;
*/
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*s = "Hello World!";
	printf("%s\n", ft_strrchr(s, 'l'));
	printf("%s\n", strrchr(s, 'l'));
}
*/