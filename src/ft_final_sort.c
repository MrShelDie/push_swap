/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:25:43 by nick              #+#    #+#             */
/*   Updated: 2022/01/29 20:37:19 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_first_orderd_idx(t_stack *stack)
{
	int	idx;

	idx = 0;
	while (stack->value != 0)
	{
		stack = stack->next;
		idx++;
	}
	return (idx);
}

void	ft_final_sort(t_prime *prime)
{
	int	idx;

	if (prime->stack_a->value == 0)
		return ;
	idx = ft_get_first_orderd_idx(prime->stack_a);
	if (idx <= prime->stack_a_size / 2)
	{
		while (idx-- > 0)
			ft_ra(prime);
	}
	else
	{
		while (idx++ < prime->stack_a_size)
			ft_rra(prime);
	}
	return ;
}
