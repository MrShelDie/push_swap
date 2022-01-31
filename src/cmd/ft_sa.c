/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 02:23:59 by nick              #+#    #+#             */
/*   Updated: 2022/01/31 02:53:10 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_prime *prime, int print)
{
	if (prime->stack_a && prime->stack_a->next)
		ft_stack_swap(prime->stack_a);
	if (print)
		write(1, "sa\n", 3);
}
