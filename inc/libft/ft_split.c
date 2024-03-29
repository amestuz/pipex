/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:41:40 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/05/09 20:23:53 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(char const *s, char c)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static int	ft_countwords(char const *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			i = i + ft_wordlen(&s[i], c);
		}
		else
			i++;
	}
	return (count);
}

static void	*free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		count;

	if (!s)
		return (NULL);
	count = ft_countwords(s, c);
	arr = (char **)malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (NULL);
	arr[count] = NULL;
	i = -1;
	j = 0;
	while (s[++i])
	{
		if (s[i] != c)
		{
			arr[j] = ft_substr(&s[i], 0, ft_wordlen(&s[i], c));
			if (!arr[j++])
				return (free_arr(arr));
			i = i + ft_wordlen(&s[i], c) - 1;
		}
	}
	return (arr);
}

/*
int	main(void)
{
	char	*s = "lorem ipsum dolor sit amet, consectetur adipiscing elit. \
	Sed non risus. Suspendissewer";
	char	c = ' ';

	ft_split(s, c);

//	printf("la string %s y el caracter %c\n", s, c);	
//	printf("%s\n", ft_split(s, c)[0]);
//	printf("%s\n", ft_split(s, c)[1]);
//	printf("%s\n", ft_split(s, c)[2]);
//	printf("%s\n", ft_split(s, c)[3]);
//	printf("%s\n", ft_split(s, c)[4]);
//	printf("%s\n", ft_split(s, c)[5]);
//	printf("%s\n", ft_split(s, c)[6]);
//	printf("%d\n", ft_count_strs(s, c));
}
*/