/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:16:01 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/05/11 00:42:20 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int				i;
	unsigned int	num;
	char			*str;

	i = ft_len(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	if (n < 0)
		num = n * -1;
	else
		num = n;
	str[i--] = '\0';
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[i--] = (num % 10) + 48;
		num = num / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

/*int	main(void)
{
	int	n = -2147483648;
	int	n2 = 147483648;

	printf("len de n es %d\n", ft_len(n));
	printf("%s\n", ft_itoa(n));
		printf("len de n2 es %d\n", ft_len(n2));
	printf("%s\n", ft_itoa(n2));
}
*/