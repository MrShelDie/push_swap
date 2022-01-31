/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 02:26:27 by nick              #+#    #+#             */
/*   Updated: 2022/01/31 02:26:31 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*new_list(void)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->len = 0;
	new->next = NULL;
	return (new);
}

t_list	*push_back_list(t_list *last)
{
	if (!last)
		return (NULL);
	last->next = new_list();
	return (last->next);
}

void	free_list_elem(t_list *elem)
{
	if (!elem)
		return ;
	free(elem);
}

void	free_list(t_list **list)
{
	t_list	*current;
	t_list	*prev;

	if (!*list)
		return ;
	current = *list;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
		free_list_elem(prev);
	}
	free_list_elem(current);
	*list = NULL;
}
