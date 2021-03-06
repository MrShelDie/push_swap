/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:39:34 by gannemar          #+#    #+#             */
/*   Updated: 2022/01/31 02:53:10 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_throw_to_a(t_prime *prime)
{
	int	i;

	i = -1;
	while (++i < 2)
	{
		if (!ft_pa(prime, TRUE))
			return (ERROR);
		if (prime->stack_a->value != 0)
			ft_ra(prime, TRUE);
	}
	return (SUCCESS);
}

void	ft_sort_3(t_prime *prime)
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
		ft_sa(prime, TRUE);
}

int	ft_sort_5(t_prime *prime)
{
	int	min;
	int	max;

	min = 0;
	max = prime->stack_a_size - 1;
	while (prime->stack_b_size < 2)
	{
		if (prime->stack_a->value == min || prime->stack_a->value == max)
		{
			if (!ft_pb(prime, TRUE))
				return (ERROR);
		}
		else
			ft_ra(prime, TRUE);
	}
	ft_sort_3(prime);
	ft_restore_stack_a(prime);
	if (!ft_throw_to_a(prime))
		return (ERROR);
	return (SUCCESS);
}
