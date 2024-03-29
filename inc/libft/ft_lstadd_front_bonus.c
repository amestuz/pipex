/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:23:48 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/05/12 21:08:25 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*
int	main(void)
{
	t_list	*new_list;
	char	str_new[] = "Kaixo";
	t_list	*previous_list;
	char	str_previous[] = "Agur";

	previous_list = malloc(sizeof(*previous_list));
	new_list = malloc(sizeof(*new_list));
	previous_list->content = (void *)str_previous;
	new_list->content = (void *)str_new;
	// Defino dos lista independientes. Ahora voy a añadir new_list a previous_list
	ft_lstadd_front(&previous_list, new_list);
	printf("El contenido del nodo nuevo es: %s", previous_list->content);
	// Ahora el puntero previous_list apunta al nodo new, de manera /
			que el content será "Kaixo"
	previous_list = previous_list->next;
	printf("     El contenido del 2º nodo es: %s", previous_list->content);
	// Y compuebo que apunta al nodo previo que es Agur
}
*/