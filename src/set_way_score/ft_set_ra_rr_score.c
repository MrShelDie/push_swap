/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_ra_rr_score.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:11:38 by nick              #+#    #+#             */
/*   Updated: 2022/01/29 18:03:44 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_ra_rr_score(t_stack *stack_b, t_way_score *way_score)
{
	if (stack_b->ra >= stack_b->rb)
		way_score->ra_rr = stack_b->ra;
	else
		way_score->ra_rr = -1;
}
