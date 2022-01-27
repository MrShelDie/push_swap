/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 02:22:51 by nick              #+#    #+#             */
/*   Updated: 2022/01/28 02:23:30 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrb(t_prime *prime)
{
	if (prime->stack_b)
		prime->stack_b = prime->stack_b->prev;
	write(1, "rrb\n", 4);
}