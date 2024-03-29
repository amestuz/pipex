/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 20:09:16 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/04/24 17:41:46 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*b;

	if (!dst && !src)
		return (NULL);
	b = (unsigned char *)dst;
	while (n--)
		b[n] = ((unsigned char *)src)[n];
	return (dst);
}
