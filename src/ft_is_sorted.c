/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 02:21:48 by nick              #+#    #+#             */
/*   Updated: 2022/01/31 02:22:06 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *stack_a, int stack_a_size)
{
	int	i;

	i = -1;
	while (++i < stack_a_size)
	{
		if (stack_a->value != i)
			break ;
		stack_a = stack_a->next;
	}
	if (i == stack_a_size)
		return (TRUE);
	return (FALSE);
}
