/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 02:15:58 by nick              #+#    #+#             */
/*   Updated: 2022/01/31 02:48:54 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pb(t_prime *prime, int print)
{
	if (prime->stack_a)
	{
		if (!ft_stack_push(&prime->stack_b, prime->stack_a->value,
				&prime->stack_b_size))
			return (ERROR);
		ft_stack_pop(&prime->stack_a, &prime->stack_a_size);
	}
	if (print)
		write (1, "pb\n", 3);
	return (SUCCESS);
}
