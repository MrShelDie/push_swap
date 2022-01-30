/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gannemar <gannemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:37:09 by nick              #+#    #+#             */
/*   Updated: 2022/01/30 16:52:04 by gannemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_argv_to_range(int argc, char **argv, int *unordered)
{
	int	i;
	int	error;

	error = SUCCESS;
	i = -1;
	while (++i < argc)
	{
		unordered[i] = ft_atoi(argv[i], &error);
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

static int	ft_fill_stack_a(t_prime *prime,
	int *unordered, int *ordered, int size)
{
	int	i;
	int	order;

	i = -1;
	while (++i < size)
	{
		order = ft_bsearch(unordered[size - i - 1], ordered, size);
		if (!ft_stack_push(&prime->stack_a, order, &prime->stack_a_size))
			return (ERROR);
	}
	return (SUCCESS);
}

int	ft_parse(int argc, char **argv, t_prime *prime, t_arg_tab *arg_tab)
{
	if (!ft_argv_to_str_tab(argc, argv, arg_tab))
		return (ERROR);
	arg_tab->ordered = (int *)malloc(sizeof(int) * arg_tab->argc);
	arg_tab->unordered = (int *)malloc(sizeof(int) * arg_tab->argc);
	if (!arg_tab->ordered || !arg_tab->unordered)
		return (ERROR);
	if (!ft_argv_to_range(arg_tab->argc, arg_tab->argv, arg_tab->unordered))
		return (ERROR);
	ft_memcpy(
		arg_tab->ordered, arg_tab->unordered, sizeof(int) * arg_tab->argc);
	ft_qsort(arg_tab->ordered, arg_tab->argc - 1);
	if (!ft_check_duplicates(arg_tab->ordered, arg_tab->argc))
		return (ERROR);
	if (!ft_fill_stack_a(
			prime, arg_tab->unordered, arg_tab->ordered, arg_tab->argc))
		return (ERROR);
	return (SUCCESS);
}
