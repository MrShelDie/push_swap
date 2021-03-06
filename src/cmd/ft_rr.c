/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 02:31:29 by nick              #+#    #+#             */
/*   Updated: 2022/01/31 02:51:19 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(t_prime *prime, int print)
{
	if (prime->stack_a)
		prime->stack_a = prime->stack_a->next;
	if (prime->stack_b)
		prime->stack_b = prime->stack_b->next;
	if (print)
		write(1, "rr\n", 3);
}
