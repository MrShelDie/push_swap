/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gannemar <gannemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:01:58 by gannemar          #+#    #+#             */
/*   Updated: 2022/01/30 16:59:54 by gannemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_prime_init(t_prime *prime)
{
	prime->stack_a = NULL;
	prime->stack_b = NULL;
	prime->stack_a_size = 0;
	prime->stack_b_size = 0;
}

void	ft_prime_free(t_prime *prime)
{
	if (prime->stack_a)
		ft_stack_free(&prime->stack_a, &prime->stack_a_size);
	if (prime->stack_b)
		ft_stack_free(&prime->stack_b, &prime->stack_b_size);
}

void	ft_free_arg_tab(t_arg_tab *arg_tab)
{
	int	i;

	i = -1;
	if (arg_tab->argv)
	{
		while (++i < arg_tab->argc)
			free(arg_tab->argv[i]);
		free(arg_tab->argv);
	}
	if (arg_tab->unordered)
		free(arg_tab->unordered);
	if (arg_tab->ordered)
		free(arg_tab->ordered);
}

void	ft_init_arg_tab(t_arg_tab *arg_tab)
{
	arg_tab->argv = NULL;
	arg_tab->argc = 0;
	arg_tab->unordered = NULL;
	arg_tab->ordered = NULL;
}

void	ft_handle_error(t_prime *prime, t_arg_tab *arg_tab)
{
	write(2, "Error\n", 6);
	ft_prime_free(prime);
	ft_free_arg_tab(arg_tab);
}
