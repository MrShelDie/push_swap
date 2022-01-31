/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 02:20:49 by nick              #+#    #+#             */
/*   Updated: 2022/01/31 02:52:03 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_prime *prime, int print)
{
	if (prime->stack_a)
		prime->stack_a = prime->stack_a->prev;
	if (print)
		write(1, "rra\n", 4);
}
