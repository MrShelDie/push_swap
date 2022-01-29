/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_all_score.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:03:29 by nick              #+#    #+#             */
/*   Updated: 2022/01/29 20:21:35 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_nearest_bigger(t_stack *stack_a, int stack_a_size, int value)
{
	int	nearest;
	int	dist;
	int	i;

	dist = INT_MAX;
	i = -1;
	while (++i < stack_a_size)
	{
		if (stack_a->value > value && stack_a->value - value < dist)
		{
			nearest = stack_a->value;
			dist = stack_a->value - value;
		}
		stack_a = stack_a->next;
	}
	return (nearest);
}

static void	ft_set_score_b(t_stack *stack_b, int stack_b_size, int pos_b)
{
	stack_b->rb = pos_b;
	stack_b->rrb = stack_b_size - pos_b;
}

static int	ft_get_elem_pos_a(t_stack *stack_a, int stack_a_size, int value_b)
{
	int	i;
	int	bigger;

	bigger = ft_get_nearest_bigger(stack_a, stack_a_size, value_b);
	i = -1;
	while (++i < stack_a_size && bigger != stack_a->value)
		stack_a = stack_a->next;
	return (i);
}

static void	ft_set_score_a(t_stack *stack_b, int stack_a_size, int pos)
{
	stack_b->ra = pos;
	stack_b->rra = stack_a_size - pos;
}

void	ft_set_all_score(t_prime *prime)
{
	int		i;
	int		pos_a;
	t_stack	*stack_b;

	stack_b = prime->stack_b;
	i = -1;
	while (++i < prime->stack_b_size)
	{
		ft_set_score_b(stack_b, prime->stack_b_size, i);
		pos_a = ft_get_elem_pos_a(prime->stack_a,
				prime->stack_a_size, stack_b->value);
		ft_set_score_a(stack_b, prime->stack_a_size, pos_a);
		stack_b = stack_b->next;
	}
}
