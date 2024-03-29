/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:11:54 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/04/25 19:46:44 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	unsigned int	up;

	up = c;
	if (c >= 97 && c <= 122)
		up = c - 32;
	return (up);
}

/*
#include <stdio.h>

int	main(void)
{
	int	c;

	c = 275;
	printf("el caracter es %i, y el up es %i\n", c, ft_toupper(c));
	return (1);
}
*/