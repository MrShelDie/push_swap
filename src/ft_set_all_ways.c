/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_all_ways.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:43:02 by nick              #+#    #+#             */
/*   Updated: 2022/01/29 18:09:21 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_way	ft_get_shortest_way(int	*ways)
{
	int	ways_size;
	int	min;
	int	way_nb;
	int	i;

	ways_size = sizeof(t_way_score) / sizeof(int);
	min = INT_MAX;
	way_nb = 0;
	i = -1;
	while (++i < ways_size)
	{
		if (ways[i] >= 0 && ways[i] < min)
		{
			min = ways[i];
			way_nb = i;
		}
	}
	return ((t_way)way_nb);
}

static void	ft_set_way(t_stack *stack_b)
{
	t_way_score	way_score;

	ft_set_ra_rr_score(stack_b, &way_score);
	ft_set_rb_rr_score(stack_b, &way_score);
	ft_set_rra_rrr_score(stack_b, &way_score);
	ft_set_rrb_rrr_score(stack_b, &way_score);
	ft_set_rra_rb_score(stack_b, &way_score);
	ft_set_ra_rrb_score(stack_b, &way_score);
	stack_b->way = ft_get_shortest_way((int *)&way_score);
	stack_b->min_score = ((int *)&way_score)[stack_b->way];
}

void	ft_set_all_ways(t_stack *stack_b, int stack_b_size)
{
	int	i;

	i = -1;
	while (++i < stack_b_size)
	{
		ft_set_way(stack_b);
		stack_b = stack_b->next;
	}
}
