/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra_rrr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:59:59 by nick              #+#    #+#             */
/*   Updated: 2022/01/31 02:52:03 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra_rrr(t_prime *prime, t_stack *elem)
{
	while (elem->rrb > 0)
	{
		ft_rrr(prime, TRUE);
		elem->rra--;
		elem->rrb--;
	}
	while (elem->rra-- > 0)
		ft_rra(prime, TRUE);
}
