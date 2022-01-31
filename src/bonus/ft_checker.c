/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 01:13:32 by nick              #+#    #+#             */
/*   Updated: 2022/01/31 03:09:32 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static int	ft_execute_cmd(t_prime *prime, char *cmd)
{
	if (!ft_strncmp(cmd, "pa\n", 4) && !ft_pa(prime, FALSE))
		return (ERROR);
	else if (!ft_strncmp(cmd, "pb\n", 4) && !ft_pb(prime, FALSE))
		return (ERROR);
	else if (!ft_strncmp(cmd, "ra\n", 4))
		ft_ra(prime, FALSE);
	else if (!ft_strncmp(cmd, "rb\n", 4))
		ft_rb(prime, FALSE);
	else if (!ft_strncmp(cmd, "rr\n", 4))
		ft_rr(prime, FALSE);
	else if (!ft_strncmp(cmd, "rra\n", 5))
		ft_rra(prime, FALSE);
	else if (!ft_strncmp(cmd, "rrb\n", 5))
		ft_rrb(prime, FALSE);
	else if (!ft_strncmp(cmd, "rrr\n", 5))
		ft_rrr(prime, FALSE);
	else if (!ft_strncmp(cmd, "sa\n", 4))
		ft_sa(prime, FALSE);
	else if (!ft_strncmp(cmd, "sb\n", 4))
		ft_sb(prime, FALSE);
	if (!ft_strncmp(cmd, "pa\n", 4) && !ft_strncmp(cmd, "pb\n", 4))
		return (ERROR);
	return (SUCCESS);
}

static int	ft_execute_program(t_prime *prime)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		if (!ft_execute_cmd(prime, cmd))
		{
			free(cmd);
			return (ERROR);
		}
		free(cmd);
		cmd = get_next_line(0);
	}
	return (SUCCESS);
}

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
	if (!ft_parse(argc, argv, &prime, &arg_tab) || !ft_execute_program(&prime))
	{
		ft_handle_error(&prime, &arg_tab);
		return (0);
	}
	if (ft_is_sorted(prime.stack_a, prime.stack_a_size))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_prime_free(&prime);
	ft_free_arg_tab(&arg_tab);
	return (0);
}
