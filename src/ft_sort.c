/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gannemar <gannemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 01:55:27 by nick              #+#    #+#             */
/*   Updated: 2022/01/30 21:02:12 by gannemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_throw_to_a(t_prime *prime)
{
	int	min;
	int	max;
	int	med;

	min = 0;
	max = prime->stack_a_size - 1;
	med = (min + max) / 2;
	while (prime->stack_a_size > 3)
	{
		if (prime->stack_a->value != min
			&& prime->stack_a->value != med
			&& prime->stack_a->value != max)
		{
			if (!ft_pb(prime))
				return (ERROR);
			if (prime->stack_b->value > med)
				ft_rb(prime);
		}
		else
			ft_ra(prime);
	}
	return (SUCCESS);
}

static t_stack	*ft_get_best_elem(t_stack *stack_b, int stack_b_size)
{
	int		i;
	int		min_score;
	t_stack	*best_elem;

	min_score = INT_MAX;
	best_elem = NULL;
	i = -1;
	while (++i < stack_b_size)
	{
		if (stack_b->min_score <= min_score)
		{
			min_score = stack_b->min_score;
			best_elem = stack_b;
		}
		stack_b = stack_b->next;
	}
	return (best_elem);
}

static int	ft_is_sorted(t_stack *stack_a, int stack_a_size)
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

int	ft_sort(t_prime *prime)
{
	t_stack	*best_elem;

	if (ft_is_sorted(prime->stack_a, prime->stack_a_size))
		return (SUCCESS);
	if (prime->stack_a_size == 5)
	{
		if (!ft_sort_5(prime))
			return (ERROR);
		return (SUCCESS);
	}
	if (!ft_throw_to_a(prime))
		return (ERROR);
	ft_sort_3(prime);
	while (prime->stack_b_size > 0)
	{
		ft_set_all_score(prime);
		ft_set_all_ways(prime->stack_b, prime->stack_b_size);
		best_elem = ft_get_best_elem(prime->stack_b, prime->stack_b_size);
		if (!ft_throw_elem_to_b(prime, best_elem))
			return (ERROR);
	}
	ft_restore_stack_a(prime);
	return (SUCCESS);
}
