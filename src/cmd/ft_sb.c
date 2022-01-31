/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 02:25:56 by nick              #+#    #+#             */
/*   Updated: 2022/01/31 02:43:18 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb(t_prime *prime, int print)
{
	if (prime->stack_b && prime->stack_b->next)
		ft_stack_swap(prime->stack_b);
	if (print)
		write(1, "sb\n", 3);
}
