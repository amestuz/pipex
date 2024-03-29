/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:00:31 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/04/28 18:30:07 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return (((unsigned char)s1[i] - (unsigned char)s2[i]));
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("(strncmp)ft_strncmp\n");
	printf("(%d)%d\n", strncmp("Hola", "Adios", 1), ft_strncmp("Hola", "Adios", 1));
	printf("(%d)%d\n", strncmp("Hola", "Adios", 0), ft_strncmp("Hola", "Adios", 0));
	printf("(%d)%d\n", strncmp("Abcd", "Bbbx", 3), ft_strncmp("Abcd", "Bbbx", 3));
	printf("(%d)%d\n", strncmp("Abcd", "Abcde", 5), ft_strncmp("Abcd", "Abcde", 5));
	printf("(%d)%d\n", strncmp("Abcd", "Abcde", 4), ft_strncmp("Abcd", "Abcde", 4));
	printf("(%d)%d\n", strncmp("B", "A", 1), ft_strncmp("B", "A", 1));
	printf("(%d)%d\n", strncmp("c", "d", 1), ft_strncmp("c", "d", 1));
	printf("(%d)%d\n", strncmp("d", "e", 1), ft_strncmp("d", "e", 1));
	printf("(%d)%d\n", strncmp("d", "d", 1), ft_strncmp("d", "d", 1));
	printf("(%d)%d\n", strncmp("e", "z", 1), ft_strncmp("e", "z", 1));
	printf("(%d)%d\n", strncmp("a", "ñ", 1), ft_strncmp("a", "ñ", 1));
	printf("(%d)%d\n", strncmp("ñ", "a", 1), ft_strncmp("ñ", "a", 1));
	return (0);
}
*/