/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:37:09 by nick              #+#    #+#             */
/*   Updated: 2022/01/28 01:08:51 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_argv_to_range(int argc, char **argv, int *range)
{
	int	i;
	int	error;

	error = SUCCESS;
	i = -1;
	while (++i < argc)
	{
		range[i] = ft_atoi(argv[i], &error);
		if (error == ERROR)
			break ;
	}
	return (error);
}

static int	ft_check_duplicates(int *ordered, int size)
{
	int	i;

	i = -1;
	while (++i < size - 1)
	{
		if (ordered[i] == ordered[i + 1])
			return (ERROR);
	}
	return (SUCCESS);
}

static int	ft_fill_stack(t_stack **stack,
	int *unordered, int *ordered, int size)
{
	int	i;
	int	order;

	i = -1;
	while (++i < size)
	{
		order = ft_bsearch(unordered[size - i - 1], ordered, size);
		if (!ft_stack_push(stack, order))
			return (ERROR);
	}
	return (SUCCESS);
}

int	ft_parse(int argc, char **argv, t_prime *prime)
{
	int	*ordered;
	int	*unordered;

	unordered = (int *)malloc(sizeof(int) * argc);
	ordered = (int *)malloc(sizeof(int) * argc);
	if (!unordered || !ordered)
		return (ERROR);
	if (!ft_argv_to_range(argc, argv, unordered))
		return (ERROR);
	ft_memcpy(ordered, unordered, sizeof(int) * argc);
	ft_qsort(ordered, argc - 1);
	if (!ft_check_duplicates(ordered, argc))
		return (ERROR);
	if (!ft_fill_stack(&prime->stack_a, unordered, ordered, argc))
		return (ERROR);
	return (SUCCESS);
}
