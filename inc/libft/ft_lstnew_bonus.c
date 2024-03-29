/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:07:32 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/05/13 19:35:25 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/*
int	main(void)
{
	char	*str = "lorem ipsum dolor sit";
	t_list	*elem;

	elem = ft_lstnew(str);
	printf("Contenido (content) del nodo creado: %s\n", elem->content);
	printf("Siguiente nodo (next) del nodo creado: %s\n", elem->next);
	//compilar sin flags para que imprima el elem->next
}
*/