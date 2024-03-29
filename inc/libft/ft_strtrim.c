/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:51:54 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/05/19 18:03:27 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int	ft_check_char(char const c, char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
*/
static int	ft_check_char(char const c, char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*s2;

	if (!s1 || !set)
		return (NULL);
	while (s1)
	{
		if (ft_check_char(*s1, set) == 1)
			s1++;
		else
			break ;
	}
	len = ft_strlen(s1);
	while (len > 0)
	{
		if (ft_check_char(s1[len - 1], set) == 1)
			len--;
		else
			break ;
	}
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, len + 1);
	return (s2);
}

/*int	main(void)
{
//	char	*s1 = "HHola mundo";
//	char	*set = "mHola";
	char	*s1 = "accccccca";
	char	*set = "a";

	printf("%s\n", ft_strtrim(s1, set));
	return (0);
}
*/