/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 00:14:02 by nick              #+#    #+#             */
/*   Updated: 2022/01/28 01:36:25 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(t_stack **stack, int value, int *stack_size)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->next = new;
	new->prev = new;
	new->value = value;
	new->min_score = -1;
	new->ra_score = -1;
	new->rb_score = -1;
	new->rra_score = -1;
	new->rrb_score = -1;
	new->push_way = NONE;
	*stack = new;
	*stack_size = 1;
	return (new);
}

t_stack	*ft_stack_push(t_stack **stack, int value, int *stack_size)
{
	t_stack	*new;

	if (!*stack)
		return (ft_stack_new(stack, value, stack_size));
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
	new->min_score = -1;
	new->ra_score = -1;
	new->rb_score = -1;
	new->rra_score = -1;
	new->rrb_score = -1;
	new->push_way = NONE;
	(*stack) = new;
	(*stack_size)++;
	return (new);
}

void	ft_stack_free(t_stack **stack, int *stack_size)
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
	(*stack_size) = 0;
}

void	ft_stack_pop(t_stack **stack, int *stack_size)
{
	t_stack	*first;
	t_stack	*last;

	if ((*stack)->next == *stack)
	{
		ft_stack_free(stack, stack_size);
		return ;
	}
	first = (*stack)->next;
	last = (*stack)->prev;
	free(*stack);
	last->next = first;
	first->prev = last;
	(*stack) = first;
	(*stack_size)--;
}

void	ft_stack_swap(t_stack *stack)
{
	int	temp;

	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
}
