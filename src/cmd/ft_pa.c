/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 02:09:52 by nick              #+#    #+#             */
/*   Updated: 2022/01/31 02:47:22 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pa(t_prime *prime, int print)
{
	if (prime->stack_b)
	{
		if (!ft_stack_push(&prime->stack_a, prime->stack_b->value,
				&prime->stack_a_size))
			return (ERROR);
		ft_stack_pop(&prime->stack_b, &prime->stack_b_size);
	}
	if (print)
		write (1, "pa\n", 3);
	return (SUCCESS);
}
