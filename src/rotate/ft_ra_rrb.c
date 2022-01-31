/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra_rrb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:12:19 by nick              #+#    #+#             */
/*   Updated: 2022/01/31 02:50:10 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra_rrb(t_prime *prime, t_stack *elem)
{
	while (elem->ra-- > 0)
		ft_ra(prime, TRUE);
	while (elem->rrb-- > 0)
		ft_rrb(prime, TRUE);
}
