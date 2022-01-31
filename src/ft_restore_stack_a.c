/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_restore_stack_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:25:43 by nick              #+#    #+#             */
/*   Updated: 2022/01/31 02:51:42 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_first_orderd_idx(t_stack *stack, int min)
{
	int	idx;

	idx = 0;
	while (stack->value != min)
	{
		stack = stack->next;
		idx++;
	}
	return (idx);
}

void	ft_restore_stack_a(t_prime *prime)
{
	int	idx;
	int	min;

	min = 0;
	if (prime->stack_b_size == 2)
		min = 1;
	if (prime->stack_a->value == min)
		return ;
	idx = ft_get_first_orderd_idx(prime->stack_a, min);
	if (idx <= prime->stack_a_size / 2)
	{
		while (idx-- > 0)
			ft_ra(prime, TRUE);
	}
	else
	{
		while (idx++ < prime->stack_a_size)
			ft_rra(prime, TRUE);
	}
	return ;
}
