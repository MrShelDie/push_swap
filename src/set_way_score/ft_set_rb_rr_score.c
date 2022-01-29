/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_rb_rr_score.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:16:12 by nick              #+#    #+#             */
/*   Updated: 2022/01/29 18:10:42 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_rb_rr_score(t_stack *stack_b, t_way_score *way_score)
{
	if (stack_b->rb >= stack_b->ra)
		way_score->rb_rr = stack_b->rb;
	else
		way_score->rb_rr = -1;
}
