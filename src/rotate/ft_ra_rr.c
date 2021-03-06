/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:52:08 by nick              #+#    #+#             */
/*   Updated: 2022/01/31 02:51:06 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra_rr(t_prime *prime, t_stack *elem)
{
	while (elem->rb > 0)
	{
		ft_rr(prime, TRUE);
		elem->rb--;
		elem->ra--;
	}
	while (elem->ra-- > 0)
		ft_ra(prime, TRUE);
}
