/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_rra_rrr_score.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:19:24 by nick              #+#    #+#             */
/*   Updated: 2022/01/29 18:07:19 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_rra_rrr_score(t_stack *stack_b, t_way_score *way_score)
{
	if (stack_b->rra >= stack_b->rrb)
		way_score->rra_rrr = stack_b->rra;
	else
		way_score->rra_rrr = -1;
}
