/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 01:55:27 by nick              #+#    #+#             */
/*   Updated: 2022/01/28 03:08:33 by nick             ###   ########.fr       */
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
		}
		else
			ft_ra(prime);
	}
	return (SUCCESS);
}

static void	ft_triple_sort(t_prime *prime)
{
	int	first;
	int	second;
	int	third;

	first = prime->stack_a->value;
	second = prime->stack_a->next->value;
	third = prime->stack_a->next->next->value;
	if ((first < second && first < third && second > third)
		|| (first > second && first < third && second < third)
		|| (first > second && first > third && second > third)
	)
		ft_sa(prime);
}

int	ft_sort(t_prime *prime)
{
	if (!ft_throw_to_a(prime))
		return (ERROR);
	ft_triple_sort(prime);
	return (SUCCESS);
}
