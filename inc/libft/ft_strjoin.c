/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:49:09 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/05/02 17:12:27 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strj;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	strj = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!strj)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		strj[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		strj[i] = s2[j];
		i++;
		j++;
	}
	strj[i] = '\0';
	return (strj);
}
