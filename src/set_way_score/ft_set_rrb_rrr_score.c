/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_rrb_rrr_score.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:54:55 by nick              #+#    #+#             */
/*   Updated: 2022/01/29 18:07:25 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_rrb_rrr_score(t_stack *stack_b, t_way_score *way_score)
{
	if (stack_b->rrb >= stack_b->rra)
		way_score->rrb_rrr = stack_b->rrb;
	else
		way_score->rrb_rrr = -1;
}
