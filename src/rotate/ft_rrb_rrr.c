/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrb_rrr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:06:45 by nick              #+#    #+#             */
/*   Updated: 2022/01/29 19:07:14 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrb_rrr(t_prime *prime, t_stack *elem)
{
	while (elem->rra > 0)
	{
		ft_rrr(prime);
		elem->rra--;
		elem->rrb--;
	}
	while (elem->rrb-- > 0)
		ft_rrb(prime);
}
