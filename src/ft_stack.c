/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 00:14:02 by nick              #+#    #+#             */
/*   Updated: 2022/01/28 00:31:59 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(t_stack **stack, int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->next = new;
	new->prev = new;
	new->value = value;
	new->ra_score = -1;
	new->rb_score = -1;
	new->rra_score = -1;
	new->rrb_score = -1;
	new->push_way = NONE;
	*stack = new;
	return (new);
}

t_stack	*ft_stack_push(t_stack **stack, int value)
{
	t_stack	*new;

	if (!*stack)
		return (ft_stack_new(stack, value));
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->next = *stack;
	new->prev = (*stack)->prev;
	if ((*stack)->next == *stack)
		(*stack)->next = new;
	(*stack)->prev->next = new;
	(*stack)->prev = new;
	new->value = value;
	new->ra_score = -1;
	new->rb_score = -1;
	new->rra_score = -1;
	new->rrb_score = -1;
	new->push_way = NONE;
	(*stack) = new;
	return (new);
}

void	ft_stack_free(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*next;

	curr = *stack;
	curr->prev->next = NULL;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*stack = NULL;
}

void	ft_stack_pop(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if ((*stack)->next == *stack)
	{
		ft_stack_free(stack);
		return ;
	}
	first = (*stack)->next;
	last = (*stack)->prev;
	free(*stack);
	last->next = first;
	first->prev = last;
	(*stack) = first;
}

void	ft_stack_swap(t_stack *stack)
{
	int	temp;

	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
}
