/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:11:54 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/04/25 20:01:46 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	unsigned int	low;

	low = c;
	if (c >= 65 && c <= 90)
		low = c + 32;
	return (low);
}

/*#include <stdio.h>

int	main(void)
{
	int	c;

	c = 'A';
	printf("el caracter es %i, y el up es %i\n", c, ft_tolower(c));
	return (1);
}
*/