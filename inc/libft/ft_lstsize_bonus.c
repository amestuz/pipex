/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:58:25 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/05/12 21:15:46 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;

	if (!lst)
		return (0);
	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*
int	main(void)
{
	t_list	*lista;
	t_list	*lista1;
	t_list	*lista2;

	lista = malloc(sizeof(t_list));
	lista1 = malloc(sizeof(t_list));
	lista2 = malloc(sizeof(t_list));
	lista->next = lista1;
	lista1->next = lista2;
	lista2->next = NULL;
	printf("El size de la lista es de: %d\n", ft_lstsize(lista));
	free(lista);
	free(lista1);
	free(lista2);
	return (0);
}
*/