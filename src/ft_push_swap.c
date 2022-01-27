/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:05:07 by nick              #+#    #+#             */
/*   Updated: 2022/01/28 01:25:48 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_prime_init(t_prime *prime)
{
	prime->stack_a = NULL;
	prime->stack_b = NULL;
	prime->stack_a_size = 0;
	prime->stack_b_size = 0;
}

static void	ft_prime_free(t_prime *prime)
{
	if (prime->stack_a)
		ft_stack_free(&prime->stack_a, &prime->stack_a_size);
	if (prime->stack_b)
		ft_stack_free(&prime->stack_b, &prime->stack_b_size);
}

static void	ft_handle_error(t_prime *prime)
{
	write(1, "Error\n", 6);
	ft_prime_free(prime);
}

int	main(int argc, char **argv)
{
	t_prime	prime;

	if (argc == 1)
		return (0);
	argc--;
	argv++;
	ft_prime_init(&prime);
	if (!ft_parse(argc, argv, &prime))
	{
		ft_handle_error(&prime);
		return (0);
	}
	return (0);
}
