/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:58:25 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/05/12 21:25:06 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != 0)
	{
		lst = lst->next;
	}
	return (lst);
}

/*
int	main(void)
{
	t_list	*lista;
	t_list	*lista1;
	t_list	*lista2;
	t_list	*last;
	char	str[] = "Soy el ultimo";

	lista = malloc(sizeof(t_list));
	lista1 = malloc(sizeof(t_list));
	lista2 = malloc(sizeof(t_list));
	last = malloc(sizeof(t_list));
	lista->next = lista1;
	lista1->next = lista2;
	lista2->content = (void *)str;
	lista2->next = NULL;
	last = ft_lstlast(lista);
	printf("El ultimo nodo de la lista contiene: %s\n", last->content);
	free(lista);
	free(lista1);
	free(lista2);
//	free(last);
	return (0);
}
*/
