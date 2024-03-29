/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:44:26 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/04/22 18:51:36 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
void	ft_bzero(void *b, size_t len)
{
	size_t			i;
	unsigned char	*str;

	str = b;
	i = 0;
	while (i < len)
		str[i++] = 0;
}
*/

void	ft_bzero(void *b, size_t len)
{
	ft_memset(b, 0, len);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[100] = "Hello World!";

	printf("%s\n", str);
	ft_bzero(str, 5);
	printf("%s\n", str);
	printf("%c\n", str[5]);
	printf("%c\n", str[6]);
}
*/