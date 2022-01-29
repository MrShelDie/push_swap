/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_all_score.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:03:29 by nick              #+#    #+#             */
/*   Updated: 2022/01/29 16:53:30 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_set_score_b(t_stack *stack_b, int stack_b_size, int pos_b)
{
	stack_b->rb = pos_b;
	stack_b->rrb = stack_b_size - pos_b;
}

static int	ft_get_elem_pos_a(t_stack *stack_a, int stack_a_size, int value_b)
{
	int	i;

	i = -1;
	while (++i < stack_a_size && value_b != stack_a->value - 1)
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
