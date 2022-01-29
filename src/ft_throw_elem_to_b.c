/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_throw_elem_to_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:45:20 by nick              #+#    #+#             */
/*   Updated: 2022/01/29 19:21:57 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_throw_elem_to_b(t_prime *prime, t_stack *elem)
{
	if (elem->way == RA_RR)
		ft_ra_rr(prime, elem);
	else if (elem->way == RB_RR)
		ft_rb_rr(prime, elem);
	else if (elem->way == RRA_RRR)
		ft_rra_rrr(prime, elem);
	else if (elem->way == RRB_RRR)
		ft_rrb_rrr(prime, elem);
	else if (elem->way == RRA_RB)
		ft_rra_rb(prime, elem);
	else
		ft_ra_rrb(prime, elem);
	if (!ft_pa(prime))
		return (ERROR);
	return (SUCCESS);
}
