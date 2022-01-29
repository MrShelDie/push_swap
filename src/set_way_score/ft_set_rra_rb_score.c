/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_rra_rb_score.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:56:34 by nick              #+#    #+#             */
/*   Updated: 2022/01/29 18:07:12 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_rra_rb_score(t_stack *stack_b, t_way_score *way_score)
{
	if (stack_b->rra >= stack_b->rb)
		way_score->rra_rb = stack_b->rra;
	else
		way_score->rra_rb = stack_b->rb;
}
