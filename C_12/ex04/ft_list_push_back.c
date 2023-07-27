/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:48:04 by aude-la-          #+#    #+#             */
/*   Updated: 2023/07/26 16:53:34 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_elem;
	t_list	*current;

	new_elem = ft_create_elem(data);
	if (new_elem == NULL)
		return ;
	if (begin_list == NULL)
		*begin_list = new_elem;
	else
	{
		current = *begin_list;
		while (current->next != NULL)
			current = current->next;
		current->next = new_elem;
	}
}
