/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:05:07 by nick              #+#    #+#             */
/*   Updated: 2022/01/31 03:20:51 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_prime		prime;
	t_arg_tab	arg_tab;

	if (argc == 1)
		return (0);
	argc--;
	argv++;
	ft_init_arg_tab(&arg_tab);
	ft_prime_init(&prime);
	if (!ft_parse(argc, argv, &prime, &arg_tab))
	{
		ft_handle_error(&prime, &arg_tab);
		return (0);
	}
	ft_sort(&prime);
	ft_prime_free(&prime);
	ft_free_arg_tab(&arg_tab);
	return (0);
}
