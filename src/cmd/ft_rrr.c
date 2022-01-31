/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 02:33:33 by nick              #+#    #+#             */
/*   Updated: 2022/01/31 02:42:53 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_prime *prime, int print)
{
	if (prime->stack_a)
		prime->stack_a = prime->stack_a->prev;
	if (prime->stack_b)
		prime->stack_b = prime->stack_b->prev;
	if (print)
		write(1, "rrr\n", 4);
}
