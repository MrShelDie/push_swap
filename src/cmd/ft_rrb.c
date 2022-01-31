/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 02:22:51 by nick              #+#    #+#             */
/*   Updated: 2022/01/31 02:52:35 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrb(t_prime *prime, int print)
{
	if (prime->stack_b)
		prime->stack_b = prime->stack_b->prev;
	if (print)
		write(1, "rrb\n", 4);
}
