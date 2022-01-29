/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_ra_rrb_score.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:00:36 by nick              #+#    #+#             */
/*   Updated: 2022/01/29 18:06:58 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_ra_rrb_score(t_stack *stack_b, t_way_score *way_score)
{
	if (stack_b->ra >= stack_b->rrb)
		way_score->ra_rrb = stack_b->ra;
	else
		way_score->ra_rrb = stack_b->rrb;
}
