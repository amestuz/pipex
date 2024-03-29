/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:04:00 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/04/22 18:52:17 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)b;
	while (i < len)
		str[i++] = (unsigned char)c;
	return (b);
}

/*#include <stdio.h>

int	main(void)
{
	char	str[100] = "Hello World!";

	printf("%s\n", str);
	printf("%s\n", ft_memset(str, 'a', 5));
	printf("%s\n", str);
}
*/